#include <chrono>
#include <cmath>
#include <condition_variable>
#include <cstdint>
#include <functional>
#include <future>
#include <mutex>
#include <numeric>
#include <print>
#include <queue>
#include <random>
#include <stop_token>
#include <thread>
#include <vector>

class ThreadPool {
public:
  explicit ThreadPool(std::size_t thread_count) {
    for (int i = 0; i < static_cast<int>(thread_count); ++i) {
      workers.emplace_back(std::bind_front(&ThreadPool::worker_loop, this));
    }
  }

  template <class F, class R = std::invoke_result_t<std::decay_t<F>>>
  [[nodiscard]] std::future<R> submit(F &&func) {
    std::packaged_task<R()> task(func);
    auto future = task.get_future();
    {
      std::lock_guard lock{m};
      jobs.push(std::move(task));
    }
    cv.notify_one();
    return future;
  }

private:
  void worker_loop(std::stop_token token) {
    // This current code block does not run the remaing tasks.
    while (true) {
      std::unique_lock lock{m};
      bool has_work = cv.wait(lock, token, [this]() { return !jobs.empty(); });
      if (!has_work) {
        return;
      }
      auto first{std::move(jobs.front())};
      jobs.pop();
      lock.unlock();
      first();
    }
  }
  std::queue<std::move_only_function<void()>> jobs;
  std::mutex m;
  std::condition_variable_any cv;
  std::vector<std::jthread> workers;
};

double simulate_chunk(std::uint64_t seed, int paths) {
  std::mt19937_64 rng{seed};
  std::normal_distribution<double> normal{0.0, 1.0};
  double payoff_sum{0.0};
  for (int i = 0; i < paths; ++i) {
    double z{normal(rng)};
    auto St = 100 * std::exp((0.05 - 0.5 * 0.2 * 0.2) * 1 + 0.2 * 1 * z);
    payoff_sum += (St - 100) > 0 ? (St - 100) : 0;
  }
  return payoff_sum;
}

int main() {
  std::vector<std::future<double>> partial;
  auto t1 = std::chrono::steady_clock::now();
  ThreadPool pool{std::thread::hardware_concurrency()};
  // TODO: submit one task per chunk c that sets partial[c]
  for (int c = 0; c < 100; ++c) {
    partial.push_back(pool.submit(
        [&, c]() { return simulate_chunk(static_cast<uint64_t>(c), 100000); }));
  }

  auto t2 = std::chrono::steady_clock::now();

  // TDO: add up partial, divide by the number of paths, discount with exp(-r *
  // T)
  auto result{std::accumulate(partial.begin(), partial.end(), 0.0,
                              [](double currSum, std::future<double> &task) {
                                currSum += task.get();
                                return currSum;
                              })};
  std::println("The final result would be: {}",
               result * std::exp(-0.05) / (100 * 100000));
  std::println("The total time it takes is: {}", t2 - t1);
}
