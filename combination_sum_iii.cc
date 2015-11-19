#include <stdio.h>

#include <vector>

class Solution {
 public:
  std::vector<std::vector<int> > CombinationSum3(int k, int n) {
    std::vector<std::vector<int> > res;
    std::vector<int> temp;
    Helper(k, n, 1, temp, res);
    return res;
  }

 private:
  bool Helper(int k, int n, int index, std::vector<int> temp, 
              std::vector<std::vector<int> >& res) {
    if (n == 0 && k == 0) {
      res.push_back(temp);
      return false;
    } else if (k < 0 || n < 0) {
      return false;
    }
    for (int i = index; i <= 9; ++i) {
      temp.push_back(i);
      if (!Helper(k - 1, n - i, i + 1, temp, res)) {
        break;
      }
      temp.pop_back();
    }
    return true;
  }
};

int main() {
  int k, n;
  scanf("%d %d", &k, &n);
  Solution solution;
  std::vector<std::vector<int> > res = solution.CombinationSum3(k, n);
  for (unsigned i = 0; i < res.size(); ++i) {
    for (unsigned j = 0; j < res[i].size(); ++j) {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
  return 0;
}
