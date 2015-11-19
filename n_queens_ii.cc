#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <string>

class Solution {
 public:
  int SolveNQueens(int n) {
    int result = 0;
    if (n <= 0) return result;
    std::vector<int> mask(n, -1);
    SolveNQueensHelper(n, 0, mask, result);
    return result;
  }

 private:
  void SolveNQueensHelper(int n, int row, std::vector<int>& mask, int& result) {
    if (row == n) {
      ++result;
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (!CheckValid(row, i, mask)) {
        continue;
      }
      mask[row] = i;
      SolveNQueensHelper(n, row + 1, mask, result); 
      mask[row] = -1;
    }
  }

  bool CheckValid(int row1, int col1, std::vector<int>& mask) {
    int row2, col2;
    for (row2 = 0; row2 < row1; ++row2) {
      col2 = mask[row2];
      if (col1 == col2) {
        return false;
      }
      if (row1 - row2 == abs(col1 - col2)) {
        return false;
      }
    } 
    return true;
  }
};

int main() {
  int n = 4;
  Solution solution;
  int result = solution.SolveNQueens(n);
  printf("%d\n", result);
  return 0;
}
