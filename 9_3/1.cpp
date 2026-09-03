#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    // check mid

    while (left < right) {
      if (nums[left] < nums[right]) {
        return nums[left];
      }
      int mid = (left + (right - left) / 2);
      // increasing for left and mid
      if (nums[left] <= nums[mid]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return nums[left];
  }
};
