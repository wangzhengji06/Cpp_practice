#include <format>
#include <print>
#include <iostream>

int main() {
  std::println("{} + {} = {}", 2, 4, 6);
  std::cout << std::format("There are {} ways I love you.", 219) << std::endl;
}

