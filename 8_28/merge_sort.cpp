#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &num) {
    help.resize(num.size());
    mergeSort(0, static_cast<int>(num.size()) - 1, num);
    return num;
  }

  void mergeSort(int l, int r, vector<int> &num) {
    if (l >= r) {
      return;
    }
    int m = (l + r) / 2;
    mergeSort(l, m, num);
    mergeSort(m + 1, r, num);
    merge(l, m, r, num);
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
