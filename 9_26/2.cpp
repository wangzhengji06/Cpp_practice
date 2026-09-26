#include <functional>
#include <print>
using namespace std::placeholders;

int add_all(int a, int b, int c) { return a + b + c; }

int main() {
  std::function<int(int, int)> f;
  std::plus<> add;
  f = add;
  std::println("{}", f(1, 2));
  f = [](int a, int b) { return a + b; };
  std::println("{}", f(1, 2));
  f = std::bind(std::ref(add_all), 0, _1, _2);
  std::println("{}", f(1, 2));
}
