#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    const int count{static_cast<int>(nums.size())};

    vector<bool> visited(nums.size());
    vector<int> path{};
    backtrack(path, nums, visited, count);
    return results;
  }

  void backtrack(vector<int> &path, const vector<int> &selections,
                 vector<bool> &visited, const int count) {
    if (path.size() == count) {
      results.push_back(path);
      return;
    }
    for (int i = 0; i < count; ++i) {
      if (visited[i] == 0) {
        visited[i] = 1;
        path.push_back(selections[i]);
        backtrack(path, selections, visited, count);
        visited[i] = 0;
        path.pop_back();
      }
    }
  }

private:
  vector<vector<int>> results;
};
