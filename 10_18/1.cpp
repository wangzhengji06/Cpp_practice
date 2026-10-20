// Problem: I need to select child array that follows equal difference. I know
// how to select child array, which is majorly done by backtrack. But how do I
// make sure it is equal difference?

// Initial Thought:
// The worst solution is after getting all the subarray that is
// >=3, I maunally test one by one whether it is equal difference. On second
// thought, when does a equal difference array being determined? When there are
// two elements in the array So I can start pruning when there are already two
// elements in the array.
//
// But how do we determine the backtrack logic? After a subarry reaches length =
// 3, it can stop here, or....

// Investigation: I implemeted the algorithm
// Observation: Now it is kind of not that good. Especiallyu because it asks for
// sub sequecne, so it should have the abiulity to jump Determiniation: I added
// the logic.

// Reflection: This is O(2^n), which is like the worst complexity

#include <unordered_map>
#include <vector>
using namespace std;
// Problem: A pretty new way of

class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &nums) {
    int n = nums.size();

    vector<unordered_map<long long, long long>> dp(n);
    long long result = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        long long diff = (long long)nums[i] - nums[j];

        long long count = dp[j][diff];

        result += count;
        dp[i][diff] += count + 1;
      }
    }
    return static_cast<int>(result);
  }
};
