#include <limits>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums) {
  int left = 0;
  int sum = 0;
  int result = numeric_limits<int>::max();
  for (int right = 0; right < static_cast<int>(nums.size()); ++right) {
    sum += nums[right];

    while (sum >= target) {
      result = min(result, right - left + 1);
      sum -= nums[left];
      ++left;
    }
  }
  return result == numeric_limits<int>::max() ? 0 : result;
}
