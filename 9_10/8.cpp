#include <print>
#include <vector>

int main() {
  std::vector<int> nums{1, 2, 3, 4, 5};
  nums.insert(nums.begin() + 2, 10);
  nums.pop_back();
  for (auto it = nums.begin(); it != nums.end(); ++it) {
    std::println("{}", *it);
  }
}
