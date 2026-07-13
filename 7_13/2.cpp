#include <print>

int main() {
  int *ptr = nullptr;
  if (ptr == nullptr) {
    std::println("ptr is not pointing to anywhere");
  }
}
