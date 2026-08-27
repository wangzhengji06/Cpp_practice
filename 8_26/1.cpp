#include <vector>

class Solution {
public:
  std::vector<int> sortArray(std::vector<int> &nums) {
    bool sorted = true;
    for (int i = nums.size() - 1; i >= 1 && sorted; --i) {
      sorted = false;
      for (int j = 0; j < i; ++i) {
        if (nums[j] > nums[j + 1]) {
          swap(nums, j, j + 1);
          sorted = true;
        }
      }
    }
    return nums;
  }

  void swap(std::vector<int> &nums, int i, int j) {
    if (i < nums.size() && j < nums.size()) {
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    }
  }
};
