#include <vector>

using namespace std;

class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) { backtrack(0, 0, board); }

  bool backtrack(int i, int j, vector<vector<char>> &board) {
    if (i == board.size()) {
      return true;
    }
    if (board[i][j] != '.') {
      if (j != board[0].size() - 1) {
        return backtrack(i, j + 1, board);
      } else {
        return backtrack(i + 1, 0, board);
      }
    }
    for (char c : selections) {
      if (isPlaceable(i, j, board, c)) {
        board[i][j] = c;
        if (j != board[0].size() - 1) {
          if (backtrack(i, j + 1, board)) {
            return true;
          };
        } else {
          if (backtrack(i + 1, 0, board)) {
            return true;
          }
        }
        board[i][j] = '.';
      }
    }
    return false;
  }

  bool isPlaceable(int i, int j, const vector<vector<char>> &board, char c) {
    for (int k = 0; k < board[0].size(); ++k) {
      if (c == board[i][k]) {
        return false;
      }
    }
    for (int k = 0; k < board.size(); ++k) {
      if (c == board[k][j]) {
        return false;
      }
    }
    for (int a = i / 3 * 3; a < i / 3 * 3 + 3; ++a) {
      for (int b = j / 3 * 3; b < j / 3 * 3 + 3; ++b) {
        if (c == board[a][b]) {
          return false;
        }
      }
    }
    return true;
  }

private:
  vector<char> selections{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
};
