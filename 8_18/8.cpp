#include <iostream>

int main() {
  int array[]{1, 2, 3, 4, 5};
  char *pointer = nullptr;

  pointer = reinterpret_cast<char *>(array);
  std::cout << pointer[0] << pointer[1] << std::endl;
}
