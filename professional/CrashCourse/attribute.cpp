#include <cstdlib>
[[deprecated("unsafe function, please use xyz")]] void func3() {}

[[nodiscard("This function is meant to provide an int.")]] int func() {
  return 42;
}

[[noreturn]] void forceProgramTermination() { exit(1); }

int func2(int param1, [[maybe_unused]] int param2) { return 42; }

int main() {
  func();
  func3();
}
