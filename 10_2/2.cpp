#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool checkDynasty(vector<int> &places) {
    // 1. ignore 0
    // 2. cannot have duplicate
    // 3. max - min < 5

    unordered_set<int> seen;
    int min_val = 14;
    int max_val = 0;

    for (int x : places) {
      if (x == 0) {
        continue;
      }
      if (seen.contains(x)) {
        return false;
      }
      seen.insert(x);

      min_val = min(min_val, x);
      max_val = max(max_val, x);
    }
    return max_val - min_val < 5;
  }
};
