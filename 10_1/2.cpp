#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1));

    dp[0][0] = poured;

    for (int i = 0; i < query_row; ++i) {
      for (int j = 0; j <= i; ++j) {
        double overflow = max(dp[i][j] - 1.0, 0.0);

        dp[i + 1][j] += overflow / 2;
        dp[i + 1][j + 1] += overflow / 2;
      }
    }

    return min(dp[query_row][query_glass], 1.0);
  }
};
