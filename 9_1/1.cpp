#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string PrintMinNumber(vector<int> &numbers) {
    // write code here
    help.resize(numbers.size());
    vector<string> nums;
    nums.reserve(numbers.size());

    for (int num : numbers) {
      nums.push_back(to_string(num));
    }

    mergeSort(nums);

    string result;
    for (const auto &s : nums) {
      result += s;
    }

    return result;
  }

  void mergeSort(vector<string> &num) {
    int l, m, r;
    int n = static_cast<int>(num.size());

    for (int step = 1; step < n; step <<= 1) {
      l = 0;
      while (l < n) {
        m = l + step - 1;
        if (m + 1 >= n) {
          break;
        }
        r = min(l + (step << 1) - 1, n - 1);
        merge(l, m, r, num);
        l = r + 1;
      }
    }
  }

  void merge(int l, int m, int r, vector<string> &num) {
    // i is the indicator
    // a is left
    // b is right
    int i = l;
    int a = l;
    int b = m + 1;

    while (a <= m && b <= r) {
      if (num[a] + num[b] < num[b] + num[a]) {
        help[i++] = num[a++];
      } else {
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
  }

private:
  vector<string> help;
};
