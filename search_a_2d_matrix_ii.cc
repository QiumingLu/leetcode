#include <stdio.h>
#include <vector>

class Solution {
 public:
  bool SearchMatrix(std::vector<std::vector<int> >& matrix, int target) {
    if (matrix.size() <= 0) {
      return false;
    } 
    int row = matrix.size(), col = matrix[0].size();
    int x = 0, y = col - 1;
    while (x < row && y >= 0) {
      if (target == matrix[x][y]) {
        return true;
      } else if (target < matrix[x][y]) {
        --y;
      } else {
        ++x;
      }
    }
    return false;
  }
};

int main() {
  int m, n;
  scanf("%d %d", &m, &n);
  std::vector<std::vector<int> > matrix(m, std::vector<int>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &matrix[i][j]);
    }
  }
  int target;
  scanf("%d", &target);
  Solution solution;
  bool res = solution.SearchMatrix(matrix, target);
  printf("%d\n", res);
  return 0;
}
