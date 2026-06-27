#include <vector>

using namespace std;

int firstMissingPositive(vector<int> &nums) {
  // iterate through nums
  // if nums[i] is in [1, n], then swap it with the value at location nums[i]
  // - 1. this should keep happening until nums[i] == num[nums[i]  -  1]

  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    while (nums[i] > 0 && nums[i] <= nums.size() &&
           nums[i] != nums[nums[i] - 1]) {
      swap(nums[i], nums[nums[i] - 1]);
    }
  }
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (nums[i] != i + 1) {
      return i + 1;
    }
  }
  return nums.size() + 1;
}
