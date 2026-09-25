#include <algorithm>
#include <iostream>
#include <print>
#include <vector>

using namespace std;

int main() {
  println("Give me a number!");
  int num;
  std::cin >> num;

  vector<int> my_vector(10);
  ranges::fill(my_vector, num);
  println("{:n}", my_vector);

  std::fill(my_vector.begin(), my_vector.end(), num);
  println("{:n}", my_vector);
}
