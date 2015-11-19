#include <stdio.h>

#include <string>
#include <vector>

class Solution {
 public:
  bool Exist(std::vector<std::vector<char> >& board, std::string word) {
    int m = board.size();
    if (m <= 0) return false;
    int n = board[0].size();
    if (n <= 0) return false;
 
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (Search(board, i, j, word, 0)) {
          return true;
        }
      }
    }
    return false;
  }

  bool Search(std::vector<std::vector<char> >& board, int i, int j,
              std::string word, int index) {
    if (index == static_cast<int>(word.size())) {
      return true;
    }
    if (i < 0 || i >= static_cast<int>(board.size()) || 
        j < 0 || j >= static_cast<int>(board[0].size()) ||
        word[index] != board[i][j]) {
      return false;
    }

    char c = board[i][j];
    board[i][j] = '#';
    int bx[4] = {0, 0, 1, -1};
    int by[4] = {-1, 1, 0, 0};
    for (int k = 0; k < 4; ++k) {
      int x = i + bx[k], y = j + by[k];
      if (Search(board, x, y, word, index + 1)) {
          return true;
      }
    }
    board[i][j] = c;
    return false;
  }
};

int main() {
  return 0;
}
