#include <stdio.h>
#include <string.h>

#include <vector>

class Solution {
 public:
  void SolveSudoku(std::vector<std::vector<char> >& board);

 private:
  const static int sudoku_size_ = 9;

  bool InitSudoku(std::vector<std::vector<char> >& board);
  bool DfsHelper(std::vector<std::vector<char> >& board, int row, int col);

  bool row_mask_[sudoku_size_][sudoku_size_];
  bool col_mask_[sudoku_size_][sudoku_size_];
  bool subboard_mask_[sudoku_size_][sudoku_size_];
};

void Solution::SolveSudoku(std::vector<std::vector<char> >& board) {
  if (!InitSudoku(board)) return;
  DfsHelper(board, 0, 0);
}

bool Solution::InitSudoku(std::vector<std::vector<char> >& board) {
  memset(row_mask_, false, sizeof(row_mask_));
  memset(col_mask_, false, sizeof(col_mask_));
  memset(subboard_mask_, false, sizeof(subboard_mask_));
  for(int i = 0; i < sudoku_size_; ++i) {
    for (int j = 0; j < sudoku_size_; ++j) {
      if (board[i][j] == '.') {
        continue;
      }
      int value = board[i][j] - '1';
      int sub_num = i/3*3 + j/3;
      if (row_mask_[i][value] || col_mask_[j][value] || 
          subboard_mask_[sub_num][value]) {
        return false;
      }
      row_mask_[i][value] = true;
      col_mask_[j][value] = true;
      subboard_mask_[sub_num][value] = true;
    }
  }
  return true;
}

bool Solution::DfsHelper(std::vector<std::vector<char> >& board, 
                         int row, 
                         int col) {
  if (row >= sudoku_size_) {
    return true;
  } 
  if (col >= sudoku_size_) {
    return DfsHelper(board, row + 1, 0);
  }
  if (board[row][col] != '.') {
    return DfsHelper(board, row, col + 1);
  }
  
  int sub_num = row/3*3 + col/3;
  for (int i = 0; i < sudoku_size_; ++i) {
    if (row_mask_[row][i] || 
        col_mask_[col][i] || 
        subboard_mask_[sub_num][i]) {
      continue;
    }
    row_mask_[row][i] = true;
    col_mask_[col][i] = true;
    subboard_mask_[sub_num][i] = true;
    board[row][col] = i + '1';
    if (DfsHelper(board, row, col + 1)) {
      return true;
    }
    row_mask_[row][i] = false;
    col_mask_[col][i] = false;
    subboard_mask_[sub_num][i] = false;
    board[row][col] = '.';
  }
  return false;
}

int main() {
  return 0;
}
