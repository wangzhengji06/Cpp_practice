#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &num) {
    int len = static_cast<int>(num.size());
    for (int i = 1; i < len; ++i) {
      int target = num[i];
      int j;
      for (j = i - 1; j >= 0; --j) {
        if (target < num[j]) {
          num[j + 1] = num[j];
        } else {
          break;
        }
      }
      num[j + 1] = target;
    }
    return num;
  }
};
