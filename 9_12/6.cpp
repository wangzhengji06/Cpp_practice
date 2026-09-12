#include <iostream>
#include <list>

int main() {
  std::list<int> mylist;

  mylist.insert(mylist.begin(), {1, 3, 5, 7, 9});
  for (int i : mylist) {
    std::cout << i << "\n";
  }
}
