#include <print>

template <typename T> void forward(T &&params) {
  process(std::forward<T>(params));
}

template <typename T> void process(T &params) { std::println("left value"); }

template <typename T> void process(T &&params) { std::println("right value"); }
