#include <print>

int add(int a, int b) { return a + b; }

using FuncPtr = int (*)(int, int);

int main() {
  FuncPtr pAdd{add};
  std::println("{}", pAdd(3, 5));
}
