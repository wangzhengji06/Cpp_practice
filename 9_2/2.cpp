#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int height = matrix.size();
    int width = matrix[0].size();
    int left = 0;
    int right = height * width - 1;

    while (left <= right) {
      int m = (left + (right - left) / 2);
      auto [a, b] = getIndex(m, width);
      if (matrix[a][b] == target) {
        return true;
      } else if (matrix[a][b] < target) {
        left = m + 1;
      } else {
        right = m - 1;
      }
    }
    return false;
  }

  pair<int, int> getIndex(int index, int width) {
    return {index / width, index % width};
  }
};
