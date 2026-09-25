#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    if (nums.size() == 2) {
      return max(nums[0], nums[1]);
    }
    if (nums.size() == 3) {
      return max(nums[0], max(nums[1], nums[2]));
    }

    vector<int> route1(nums.size() - 1);
    vector<int> route2(nums.size() - 1);

    route1[0] = nums[0];
    route1[1] = max(nums[0], nums[1]);

    route2[0] = nums[1];
    route2[1] = max(nums[1], nums[2]);

    for (int i = 2; i < route1.size(); ++i) {
      route1[i] = max(route1[i - 1], route1[i - 2] + nums[i]);
      route2[i] = max(route2[i - 1], route2[i - 2] + nums[i + 1]);
    }

    return max(route1[route1.size() - 1], route2[route2.size() - 1]);
  }
};
