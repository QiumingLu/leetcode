#include <stdio.h>

#include <vector>

class Solution {
 public:
  bool IsValidSudoku(std::vector<std::vector<int> >& board) {
    const int count = 9;
    bool row_mask[count][count] = {false};
    bool col_mask[count][count] = {false};
    bool subboard_mask[count][count] = {false};
    for (int i = 0; i < count; ++i) {
      for (int j = 0; j < count; ++j) {
        if (board[i][j] == '.') { 
          continue;
        }
        int value = board[i][j] - '1';
        if (row_mask[i][value] == true) {
          return false;
        }
        row_mask[i][value] = true;
        if (col_mask[value][j] == true) {
          return false;
        }
        col_mask[value][j] = true;
        int number = i/3*3 + j/3;
        if (subboard_mask[number][value] == true) {
          return false;
        }
        subboard_mask[number][value] = true;
      }
    }
    return true;
  }
};

int main() {
  return 0;
}
