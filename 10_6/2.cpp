#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    vector<vector<int>> dp{triangle.size()};
    for (int i = 0; i < triangle.size(); ++i) {
      dp[i].assign(triangle[i].size(), numeric_limits<int>::max());
    }
    dp[0][0] = triangle[0][0];
    for (int i = 0; i < dp.size() - 1; ++i) {
      for (int j = 0; j < dp[i].size(); ++j) {
        dp[i + 1][j] = min(dp[i][j] + triangle[i + 1][j], dp[i + 1][j]);
        dp[i + 1][j + 1] =
            min(dp[i][j] + triangle[i + 1][j + 1], dp[i + 1][j + 1]);
      }
    }
    return ranges::min(dp[dp.size() - 1]);
  }
};
