#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <string>

class Solution {
 public:
  std::vector<std::vector<std::string> > SolveNQueens(int n) {
    std::vector<std::vector<std::string> > result;
    if (n <= 0) return result;
    std::vector<int> mask(n, -1);
    SolveNQueensHelper(n, 0, mask, result);
    return result;
  }

 private:
  void SolveNQueensHelper(int n, int row, std::vector<int>& mask, 
                          std::vector<std::vector<std::string> >& result) {
    if (row == n) {
      std::vector<std::string> v(n, std::string(n, '.'));
      for (int i = 0; i < n; ++i) {
        int c = mask[i];
        v[i][c] = 'Q';
      }
      result.push_back(v);
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
  std::vector<std::vector<std::string> > result = solution.SolveNQueens(n);
  for (size_t i = 0; i < result.size(); ++i) {
    printf("[");
    for (size_t j = 0; j < result[i].size(); ++j) {
      printf("\"%s,\"\n", result[i][j].c_str());
    }
    printf("]\n");
  }
  return 0;
}
