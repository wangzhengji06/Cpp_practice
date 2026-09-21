#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> path{};
    vector<int> selections{1, 2, 3, 4, 5, 6, 7, 8, 9};
    backtrack(path, selections, 0, k, n);
    return result;
  }
  void backtrack(vector<int> &path, const vector<int> &selections, int start,
                 int k, int n) {
    if (n == 0 && k == 0) {
      result.push_back(path);
      return;
    }
    if (k < 0 || n < 0) {
      return;
    }

    for (int i = start; i < selections.size(); ++i) {
      path.push_back(selections[i]);
      backtrack(path, selections, i + 1, k - 1, n - selections[i]);
      path.pop_back();
    }
  }

private:
  vector<vector<int>> result;
};
