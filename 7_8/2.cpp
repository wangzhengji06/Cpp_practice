#include <iostream>

void show(int value) { std::cout << value << std::endl; }

void show(float value) { std::cout << value << std::endl; }

int main() {
  show(3.0);
  float value = 3.0;
  show(value);
  float value2 = 3.0f;
  show(value2);
}
