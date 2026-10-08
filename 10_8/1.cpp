#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row_num{static_cast<int>(matrix.size())};
    int col_num{static_cast<int>(matrix[0].size())};

    int row = 0;
    int col = col_num - 1;
    while (row < row_num && col >= 0) {
      if (matrix[row][col] == target) {
        return true;
      } else if (matrix[row][col] < target) {
        row++;
      } else {
        col--;
      }
    }
    return false;
  }
};
