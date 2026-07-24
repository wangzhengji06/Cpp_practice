#include <print>

static int nice_global = 9;

void test() {
  static int nice_local = 1;
  nice_global++;
  nice_local++;
  std::println("nice_global: {}, nice_local: {}", nice_global, nice_local);
}

int main() {
  test();
  test();
  test();

  std::println("main can access nice_global: {}", nice_global);
}
