#include <iostream>
#include <print>
#include <vector>

int main() {
  std::vector<int> values{2, 5};
  values.insert(values.begin() + 1, 3);
  values.insert(values.begin() + 2, 4);
  std::vector<int> new_values{0, 1};
  values.insert(values.begin(), new_values.begin(), new_values.end());
  std::vector<int> third_values;
  for (auto iterator = values.rbegin(); iterator != values.rend(); ++iterator) {
    third_values.push_back(*iterator);
  }
  std::println("{:n}", third_values);
  for (int i : third_values) {
    std::cout << i << " ";
  }
}
