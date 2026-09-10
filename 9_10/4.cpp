#include <iostream>
#include <vector>

int main() {
  std::vector<int> array{1, 2, 3, 4, 5};
  auto it1 = ++array.begin();
  array.insert(array.begin() + 1, 15);
  std::cout << "The iterator is now invalid.\n";
}
