#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int curr = 0;
    int insert = 0;

    while (curr != nums.size()) {
      if (curr == 0 || nums[curr] != nums[curr - 1]) {
        nums[insert++] = nums[curr];
      }
      curr++;
    }

    return insert;
  }
};
