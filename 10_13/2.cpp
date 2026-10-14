// Problem
// I need to use dynamic programming and express the value of the profit using
// the provided state: days, hold/not hold.
// The hard point is how to capture the state of someone doing the second deal
// or the first deal.
// Initial Reasoning
// I can use dp[i][j][k], where [j] stands for hold or not, while k stands for
// the pruchase he has made. 0 -> can sell or buy 1 -> can sell or buy 2 ->
// cannot sell or buy
// Investigation:
// Observation:
// Tracking only the day and holding status is inefficient.
// Hypothesis:
// I can use dp[i][j][k], where k represents the exact
// number of purchases made
// // Evidence:
// 1. A purchase increases k by one.
// 2. A sale does not change k.
// 3. Buying is only allowed when no stock is held.
// 4. Selling is only allowed when a stock is held.
// 5. Unreachable states must be distinguished from states
//    with zero profit.

// Determination:
// Use the hypothesis method
// Reflection:
// 1. Some initial states are illegale, need to prevent value transported from such illegal state
// 2. THe state need to be as much specific as possible. This is better for mental model
// 3. If the next state depends only on the previous state, we don't need to preserve the entire history.

#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = static_cast<int>(prices.size());
    constexpr int NEG = numeric_limits<int>::min() / 4;
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(2, vector<int>(3, NEG)));
    dp[0][0][0] = 0;

    for (int i = 1; i <= n; ++i) { // i is the day
      for (int k = 0; k < 3;
           ++k) { // k is how many transactions already happened

        // Not holding
        dp[i][0][k] = dp[i - 1][0][k];
        if (dp[i - 1][1][k] != NEG) {
          dp[i][0][k] = max(dp[i][0][k], dp[i - 1][1][k] + prices[i - 1]);
        }
        dp[i][1][k] = dp[i - 1][1][k];
        // Holding: buy today.
        if (k > 0 && dp[i - 1][0][k - 1] != NEG) {
          dp[i][1][k] = max(dp[i][1][k], dp[i - 1][0][k - 1] - prices[i - 1]);
        }
      }
    }

    return max({dp[n][0][0], dp[n][0][1], dp[n][0][2]});
  }
};
