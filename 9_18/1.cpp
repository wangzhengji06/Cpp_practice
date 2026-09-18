#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> path;
    backtrack(path, candidates, target, 0);
    return result;
  }

  void backtrack(vector<int> &path, vector<int> &selections, int target,
                 int start) {
    if (target == 0) {
      result.push_back(path);
      return;
    }
    if (target < 0) {
      return;
    }
    for (int i = start; i < selections.size(); ++i) {

      path.push_back(selections[i]);
      backtrack(path, selections, target - selections[i], i);
      path.pop_back();
    }
  }

private:
  vector<vector<int>> result;
};
