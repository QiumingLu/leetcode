#include <stdio.h>

#include <vector>

class Solution {
 public:
  void GameOfLife(std::vector<std::vector<int> >& board) {
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();
    if (n == 0) return;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0,  1, -1, 1,-1, 0, 1};

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int count = 0;
        for (int k = 0; k < 8; ++k) {
          int x = i + dx[k];
          int y = j + dy[k];
          if (x >= 0 && x < m && y >= 0 && y < n && 
              (board[x][y] == 1 || board[x][y] == 2)) {
            ++count;
          }
        }
        if (board[i][j] == 1) {
          if (count < 2 || count > 3) {
            board[i][j] = 2;
          }
        }

        if (board[i][j] == 0) {
          if (count == 3) {
            board[i][j] = 3;
          }
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
          board[i][j] %= 2;
      }
    }
  }
};

int main() {
  return 0;
}
