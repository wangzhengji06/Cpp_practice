#include <vector>

using namespace std;

class Solution {
public:
  int reversePairs(vector<int> &record) {
    help.resize(record.size());
    return static_cast<int>(mergeSort(record));
  }

  long long mergeSort(vector<int> &num) {
    int l, m, r;
    int n = static_cast<int>(num.size());
    long long ans = 0;
    for (int step = 1; step < n; step <<= 1) {
      l = 0;
      while (l < n) {
        m = l + step - 1;
        if (m + 1 >= n) {
          break;
        }
        // this is import, right is either the n - 1, or the l + step *  2 - 1
        r = min(l + (step << 1) - 1, n - 1);
        ans += merge(l, m, r, num);
        l = r + 1;
      }
    }
    return ans;
  }

  long long merge(int l, int m, int r, vector<int> &num) {
    // i is indicator of where it is
    // a is the left
    // b is the right
    int i = l;
    int a = l;
    int b = m + 1;

    long long ans = 0;

    while (a <= m && b <= r) {
      if (num[a] <= num[b]) {
        help[i++] = num[a++];
      } else {
        ans += m - a + 1;
        help[i++] = num[b++];
      }
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
