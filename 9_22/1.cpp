#include <vector>

using namespace std;

class Solution {
public:
  int fib(int n) {
    vector<int> cache(n + 1);
    if (n <= 1) {
      return n;
    }
    cache[0] = 0;
    cache[1] = 1;
    for (int i = 2; i <= n; ++i) {
      cache[i] = cache[i - 1] + cache[i - 2];
    }
    return cache[n];
  }
};
