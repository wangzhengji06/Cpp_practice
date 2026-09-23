#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    if (cost.size() <= 1) {
      return 0;
    }
    vector<int> result(cost.size() + 1);
    result[0] = 0;
    result[1] = 0;

    for (int i = 2; i <= cost.size(); ++i) {
      result[i] = min(result[i - 2] + cost[i - 2], result[i - 1] + cost[i - 1]);
    }

    return result[result.size() - 1];
  }
};
