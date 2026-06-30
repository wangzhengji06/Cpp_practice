#include <cstring>
#include <iostream>
#include <vector>

int main() {
  const char *cstr{"nothing"};
  std::cout << strlen(cstr) << std::endl;

  std::vector ints{1, 2, 3};
  std::vector names{"James", "Tom"};
}
