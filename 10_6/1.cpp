#include <print>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool canCross(vector<int> &stones) {
    //[0,1,3,5,6,8,12,17]

    // dp[i] stores what? it should store a list of how many steps it can take
    // to reach it from last jump

    // dp[0] = {0} 0
    // dp[1] = {1} 1
    // dp[2] = {2} 3
    // dp[3] = {2} 5
    // dp[4] = {3,1}  6
    // dp[5] = {2,3}  8
    // dp[6] = {4} 12
    // dp[7] = {5} 17
    // dp[i] = for every previous j < i, calculate val =  stones[i] - stones[j],
    // and check whether val+1, val-1, val is in dp[j] +1. if exists, append val
    // into dp[i]
    vector<unordered_set<int>> dp(stones.size());
    dp[0] = {0};
    for (int i = 1; i < dp.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (stones[i] - stones[j] > j + 1) {
          continue;
        }
        long long val = static_cast<long long>(stones[i]) - stones[j];
        if (dp[j].contains(val) || dp[j].contains(val - 1) ||
            dp[j].contains(val + 1)) {
          dp[i].insert(val);
        }
      }
    }

    println("{:n}", dp);
    return !dp[dp.size() - 1].empty();
  }
};

int main() {
  vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
  Solution solution{};
  println("{}", solution.canCross(stones));
}
