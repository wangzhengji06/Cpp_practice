#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val) {
  int count = 0;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (nums[i] == val) {
      ++count;
    } else {
      nums[i-count] = nums[i];
    }

  }

  
}
