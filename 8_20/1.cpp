#include <exception>
#include <iostream>
#include <stdexcept>

double divide(int a, int b) {
  if (b == 0) {
    throw std::runtime_error("Division By zero is not allowed");
  }
  return static_cast<double>(a) / static_cast<double>(b);
}

int main() {
  try {
    double result = divide(1, 0);
  } catch (const std::exception &e) {
    std::cout << "Caught an exception: " << e.what() << std::endl;
  }
}
