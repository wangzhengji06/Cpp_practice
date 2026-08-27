#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    for (int gap = nums.size() / 2; gap > 0; gap /= 2) {

      for (int i = gap; i < nums.size(); ++i) {
        int target = nums[i];
        int j;
        for (j = i - gap; j >= 0; j -= gap) {
          if (target < nums[j]) {
            nums[j + gap] = nums[j];
          } else {
            break;
          }
        }
        nums[j + gap] = target;
      }
    }
    return nums;
  }
};
