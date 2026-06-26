#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums) {
  int max = 0;
  int count = 0;
  for (int num : nums) {
    if (num == 1) {
      ++count;
      max = max > count ? max : count;
    } else {
      count = 0;
    }
  }
  return max;
}

