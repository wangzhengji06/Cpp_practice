#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <print>
#include <queue>
#include <stop_token>
#include <thread>
#include <vector>

class ThreadPool {
public:
  // create jthreads inside workers, the jthreads is running worker_loop
  // function with this as its binding.
  explicit ThreadPool(std::size_t thread_count) {
    for (int i = 0; i < static_cast<int>(thread_count); ++i) {
      workers.emplace_back(std::bind_front(&ThreadPool::worker_loop, this));
    }
  }
  // decay_t removes the reference / const modifier and apply a function pointer
  // decay
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
  // wait on conditional variable,
  // if stopped then return, else take the lock, and start operating on the jobs
  // query.
  void worker_loop(std::stop_token token) {
    // TODO: wait for work or stop, then run tasks
    while (!token.stop_requested()) {
      std::unique_lock lock{m};
      // What if it is suprious wake-up?  Then it would keep waiting
      bool has_work = cv.wait(lock, token, [this]() {
        return !jobs.empty();
      }); // stop_requested() == true && jobs.empty == false;
      if (!has_work) {
        return;
      }
      auto first{std::move(jobs.front())};
      jobs.pop();
      lock.unlock();
      first();
    }
  }
  // TODO: members (think about the order!)
  std::queue<std::move_only_function<void()>> jobs;
  std::mutex m;
  std::condition_variable_any cv;
  std::vector<std::jthread> workers;
};
int main() {
  ThreadPool pool{4};
  for (int i{0}; i < 8; ++i) {
    pool.submit([p = std::make_unique<int>(42)] { std::println("{}", *p); });
  }
}
