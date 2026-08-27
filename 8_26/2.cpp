#include <vector>

class Solution {
public:
  std::vector<int> sortArray(std::vector<int> &nums) {
    int n = static_cast<int>(nums.size());
    int minIndex;
    for (int i = 0; i < n - 1; ++i) {
      minIndex = i;
      for (int j = i + 1; j < n; ++j) {
        if (nums[j] < nums[minIndex]) {
          minIndex = j;
        }
      }
      swap(nums, i, minIndex);
    }
    return nums;
  }

private:
  void swap(std::vector<int> &nums, int i, int j) {
    if (i < nums.size() && j < nums.size()) {
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    }
  }
};
