#include <print>
#include <vector>

void double_list(std::vector<int> &nums) {
  for (auto iterator = nums.begin(); iterator != nums.end(); ++iterator) {
    *iterator *= 2;
  }
}

int main() {
  std::vector<int> nums{1, 2, 3, 4, 5};
  double_list(nums);
  std::println("{:n}", nums);
}
