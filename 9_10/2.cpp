#include <iostream>
#include <vector>

int main() {
  std::vector<int> nice{1, 2, 3, 4, 5};
  for (auto iterator = nice.begin(); iterator != nice.end(); ++iterator) {
    std::cout << *iterator << "\n";
  }
}
