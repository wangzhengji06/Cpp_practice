#include <iostream>
#include <vector>

int main() {
  std::vector<int> numbers{};
  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_back(4);
  numbers.push_back(5);

  for (auto iterator = numbers.begin(); iterator != numbers.end(); ++iterator) {
    std::cout << *iterator << "\n";
  }
}
