#include <algorithm>
#include <iostream>
#include <print>
#include <vector>

using namespace std;

int main() {
  std::cout << "Please enter a few numbers" << "\n";
  int num;
  vector<int> my_vec;
  while (std::cin >> num) {
    my_vec.push_back(num);
  }
  ranges::sort(my_vec);
  do {
    println("{:n}", my_vec);
  } while (ranges::next_permutation(my_vec).found);

  do {
    println("{:n}", my_vec);
  } while (next_permutation(my_vec.begin(), my_vec.end()));
}
