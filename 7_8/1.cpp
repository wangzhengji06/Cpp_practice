#include <iostream>

void print(int value) { std::cout << value << std::endl; }

void print(double value) { std::cout << value << std::endl; }

void print(const char *value) { std::cout << value << std::endl; }

int main() {
  print(5);
  print(4.2);
  print("nice");
}
