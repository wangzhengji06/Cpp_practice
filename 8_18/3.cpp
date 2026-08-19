#include <iostream>
#include <vector>

int main() {
  std::vector<int> example{1, 2, 3, 4, 5};
  for (int i = 0; i < example.size(); ++i) {
    std::cout << example[i] << " ";
  }
  std::cout << "\n";
}
