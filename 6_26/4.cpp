#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
  vector<vector<int>> result(n, vector<int>(n, 0));
  int left = 0;
  int right = n - 1;
  int top = 0;
  int bottom = n - 1;

  int num = 1;

  while (left <= right && top <= bottom) {
    for (int i = left; i <= right; ++i) {
      result[top][i] = num;
      ++num;
    }
    ++top;

    for (int i = top; i <= bottom; ++i) {
      result[i][right] = num;
      ++num;
    }
    --right;

    if (top <= bottom) {
      for (int i = right; i >= left; --i) {
        result[bottom][i] = num;
        ++num;
      }
      --bottom;
    }

    if (left <= right) {
      for (int i = bottom; i >= top; --i) {
        result[i][left] = num;
        ++num;
      }
      ++left;
    }
  }
  return result;
}
