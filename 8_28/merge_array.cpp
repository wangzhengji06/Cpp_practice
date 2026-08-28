#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &num) {
    help.resize(num.size());
    mergeSort(num);
    return num;
  }

  void mergeSort(vector<int> &num) {
    int l, m, r;
    int n = static_cast<int>(num.size());
    for (int step = 1; step < n; step <<= 1) {
      l = 0;
      while (l < n) {
        m = l + step - 1;
        if (m + 1 >= n) {
          break;
        }
        // this is import, right is either the n - 1, or the l + step *  2 - 1
        r = min(l + (step << 1) - 1, n - 1);
        merge(l, m, r, num);
        l = r + 1;
      }
    }
  }

  void merge(int l, int m, int r, vector<int> &num) {
    // i is indicator of where it is
    // a is the left
    // b is the right
    int i = l;
    int a = l;
    int b = m + 1;

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
  }

private:
  vector<int> help;
};
