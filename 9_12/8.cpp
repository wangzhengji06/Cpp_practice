#include <iostream>
#include <list>

int main() {
  std::list<int> my_list;
  my_list.insert(my_list.begin(), {9, 3, 5, 1, 7});
  for (int i : my_list) {
    std::cout << i << "\n";
  }

  my_list.sort();
  for (int i : my_list) {
    std::cout << i << "\n";
  }

  my_list.reverse();
  for (int i : my_list) {
    std::cout << i << "\n";
  }
}
