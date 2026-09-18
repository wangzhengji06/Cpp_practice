#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<int> path;
    // First sort
    // Then skip the same element
    sort(candidates.begin(), candidates.end());
    backtrack(path, candidates, target, 0);
    return result;
  }

  void backtrack(vector<int> &path, const vector<int> &selections, int target,
                 int start) {
    if (target == 0) {
      result.push_back(path);
      return;
    }
    for (int i = start; i < selections.size(); ++i) {
      if (i != start && selections[i] == selections[i - 1]) {
        continue;
      }
      if (selections[i] > target) {
        break;
      }
      path.push_back(selections[i]);
      backtrack(path, selections, target - selections[i], i + 1);
      path.pop_back();
    }
  }

private:
  vector<vector<int>> result;
};
