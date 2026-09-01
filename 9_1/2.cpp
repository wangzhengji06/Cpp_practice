#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int reversePairs(vector<int> &nums) {
    help.resize(nums.size());
    return mergeSort(nums);
  }

  int mergeSort(vector<int> &num) {
    int l, m, r;
    long long ans = 0;
    int n = static_cast<int>(num.size());
    for (int step = 1; step < n; step <<= 1) {
      l = 0;
      while (l < n) {
        m = l + step - 1;
        if (m + 1 >= n) {
          break;
        }
        r = min(l + (step << 1) - 1, n - 1);
        ans += merge(l, m, r, num);
        l = r + 1;
      }
    }
    return ans;
  }

  int merge(int l, int m, int r, vector<int> &num) {
    int i = l;
    int a = l;
    int b = m + 1;
    int ans = 0;
    while (a <= m && b <= r) {
      if (static_cast<long>(num[a]) > 2LL * num[b]) {
        ans += m - a + 1;
        ++b;
      } else {
        ++a;
      }
    }

    a = l;
    b = m + 1;

    while (a <= m && b <= r) {
      help[i++] = (num[a] <= num[b] ? num[a++] : num[b++]);
    }

    while (a <= m) {
      help[i++] = num[a++];
    }

    while (b <= r) {
      help[i++] = num[b++];
    }

    for (int j = l; j <= r; ++j) {
      num[j] = help[j];
    }

    return ans;
  }

private:
  vector<int> help;
};
