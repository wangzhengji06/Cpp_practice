#include <vector>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int result{0};
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == '1') {
          ++result;
          dfsTransform(i, j, grid);
        }
      }
    }
    return result;
  }

  void dfsTransform(int i, int j, vector<vector<char>> &grid) {
    if (i < 0 | i >= grid.size() | j < 0 | j >= grid[0].size()) {
      return;
    }
    if (grid[i][j] == '1') {
      grid[i][j] = '0';
      dfsTransform(i + 1, j, grid);
      dfsTransform(i - 1, j, grid);
      dfsTransform(i, j - 1, grid);
      dfsTransform(i, j + 1, grid);
    } else {
      return;
    }
  }
};
