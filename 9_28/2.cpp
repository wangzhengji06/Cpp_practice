#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int left{0};
    int right{static_cast<int>(nums.size()) - 1};
    vector<int> result(nums.size());
    int pos = nums.size() - 1;
    while (pos >= 0) {
      if (nums[left] * nums[left] >= nums[right] * nums[right]) {
        result[pos] = nums[left] * nums[left];
        left++;
      } else {
        result[pos] = nums[right] * nums[right];
        right--;
      }
      pos--;
    }
    return result;
  }
};
