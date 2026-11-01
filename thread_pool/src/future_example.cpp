#include <exception>
#include <future>
#include <print>
#include <thread>

int main() {
  std::promise<int> promise{};
  std::future<int> future{promise.get_future()};
  std::jthread worker{[&promise] { promise.set_value(6 * 7); }};
  std::println("{}", future.get());

  // packaged_task
  std::packaged_task<int()> task([]() { return 6 * 7; });
  auto future_2 = task.get_future();
  std::jthread worker_2{task};
  try {
    std::println("{}", future_2.get());
  } catch (const std::exception &e) {
    std::println("{}", e.what());
  }
}
