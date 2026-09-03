#include <iostream>

template <typename... Args> int sum(Args... values) {
  return (0 + ... + values);
}

int main() { std::cout << sum(1, 2, 3) << "\n"; }
