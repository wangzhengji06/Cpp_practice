#include <algorithm>
#include <iostream>
#include <vector>

void sortv(std::vector<int>::iterator it1, std::vector<int>::iterator it2) {
  std::sort(it1, it2);
}

int main() {
  std::vector<int> s{1, 9, 2, 5, 7, 6};

  sortv(s.begin(), s.end());

  for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << ' ';
  }
}
