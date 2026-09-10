#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main() {
  std::vector<int> nums;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(1, 10);

  for (int i = 0; i < 15; ++i) {
    nums.push_back(dist(gen));
  }

  std::sort(nums.begin(), nums.end());

  auto new_end = std::unique(nums.begin(), nums.end());
  nums.erase(new_end, nums.end());

  int target = 5;
  auto it = std::find(nums.begin(), nums.end(), target);

  for (auto value : nums) {
    std::cout << value << ' ';
  }
  std::cout << '\n';

  if (it != nums.end()) {
    std::cout << "Found: " << *it << '\n';
  } else {
    std::cout << target << " not found\n";
  }
}
