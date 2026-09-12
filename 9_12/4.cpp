#include <array>
#include <iostream>
int main() {
  std::array<int, 5> arr{1, 2, 3, 4, 5};
  for (int i : arr) {
    std::cout << i << std::endl;
  }
}
