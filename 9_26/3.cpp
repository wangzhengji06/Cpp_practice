#include <functional>
#include <print>
using namespace std::placeholders;

int minus(int a, int b) { return a - b; }

int main() {
  auto f = std::bind(minus, 10, _1);

  std::println("{}", f(2));
}
