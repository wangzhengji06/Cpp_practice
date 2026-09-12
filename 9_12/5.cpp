#include <array>
#include <iostream>

void double_array(std::array<int, 5> &arr) {
  for (auto &number : arr) {
    number *= 2;
  }
}

int main() {
  std::array<int, 5> arr{1, 2, 3, 4, 5};
  double_array(arr);
  for (int i : arr) {
    std::cout << i << std::endl;
  }
}
