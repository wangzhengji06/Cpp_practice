#include <print>
#include <utility>

template <typename T> void process(T &data) {
  std::println("a left value version is called");
}

template <typename T> void process(T &&data) {
  std::println("a right value version is called");
}

template <typename... T> void process_wrapper(T &&...args) {
  (process(std::forward<T>(args)), ...);
}

int main() {
  process_wrapper(20, 30);
  int a = 30;
  int b = 40;
  process_wrapper(a, b);
}
