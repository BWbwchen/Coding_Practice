#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool seen = false;
  vector<vector<bool>> visited;
  void solve(vector<vector<char>> &board) {
    visited = vector<vector<bool>>(board.size(),
                                   vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == 'O' && !visited[i][j]) {
          find(board, i, j);
          if (!seen) {
            mark(board, i, j);
          }
          seen = false;
        }
      }
    }
  }
  void find(vector<vector<char>> &board, int i, int j) {
    // out of range
    if (j >= board[0].size() || i >= board.size() || j < 0 || i < 0)
      return;

    if (board[i][j] == 'X' || visited[i][j])
      return;

    // on the edge or not
    if (j == board[0].size() - 1 || i == board.size() - 1 || j == 0 || i == 0) {
      seen = true;
    }

    visited[i][j] = true;
    // down
    find(board, i + 1, j);

    // up
    find(board, i - 1, j);

    // left
    find(board, i, j - 1);

    // right
    find(board, i, j + 1);
  }
  void mark(vector<vector<char>> &board, int i, int j) {
    // out of range
    if (j >= board[0].size() || i >= board.size() || j < 0 || i < 0)
      return;

    if (board[i][j] == 'X')
      return;

    board[i][j] = 'X';

    // down
    mark(board, i + 1, j);

    // up
    mark(board, i - 1, j);

    // left
    mark(board, i, j - 1);

    // right
    mark(board, i, j + 1);
  }
};
