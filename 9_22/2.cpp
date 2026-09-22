#include <vector>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    vector<int> cache(n + 1);
    if (n == 0 || n == 1) {
      return n;
    }
    if (n == 2) {
      return 2;
    }
    cache[0] = 1;
    cache[1] = 1;
    for (int i = 2; i <= n; ++i) {
      cache[i] = cache[i - 1] + cache[i - 2];
    }

    return cache[n];
  }
};
