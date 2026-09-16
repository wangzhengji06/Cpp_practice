#include <vector>

using namespace std;

class Solution {
public:
  void solve(vector<vector<char>> &board) {
    // step 1: Starting from the boundary, dfs all the O that is connected to
    // boundary, and replace them with # step 2: Iterate over the board, O -> X
    // , # -> O
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (i == 0 || i == board.size() - 1 || j == 0 ||
            j == board[0].size() - 1) {
          dfsTransform(i, j, board);
        }
      }
    }
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == '#') {
          board[i][j] = 'O';
        }
      }
    }
  }

  void dfsTransform(int i, int j, vector<vector<char>> &board) {
    if (i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1) {
      return;
    }
    if (board[i][j] == 'O') {
      board[i][j] = '#';
      dfsTransform(i + 1, j, board);
      dfsTransform(i - 1, j, board);
      dfsTransform(i, j - 1, board);
      dfsTransform(i, j + 1, board);
    } else {
      return;
    }
  }
};
