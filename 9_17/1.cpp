#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> path;
    backtrack(path, 1, n, k);
    return results;
  }

  void backtrack(vector<int> path, int start, int n, int k) {
    if (path.size() == k) {
      results.push_back(path);
      return;
    }

    for (int i = start; i <= n; ++i) {
      path.push_back(i);
      backtrack(path, i + 1, n, k);
      path.pop_back();
    }
  }

private:
  vector<vector<int>> results;
};
