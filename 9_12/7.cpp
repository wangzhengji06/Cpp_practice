#include <iostream>
#include <iterator>
#include <list>

void insert_wrapper(std::list<int> &my_list, int value, int position) {
  auto pos = my_list.begin();
  if (position >= static_cast<int>(my_list.size())) {
    pos = my_list.end();
  } else {
    std::advance(pos, position);
  }

  my_list.insert(pos, value);
}

int main() {
  std::list<int> lst{1, 3, 5, 7, 9};

  insert_wrapper(lst, 11, 2);

  for (int x : lst) {
    std::cout << x << '\n';
  }
}
