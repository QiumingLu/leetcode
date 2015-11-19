#include <stdio.h>

#include <vector>
#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<int> > CombinationSum(
      std::vector<int>& candidates, 
      int target) {
    std::vector<std::vector<int> > res;
    if (candidates.size() <= 0) {
      return res;
    }
    std::sort(candidates.begin(), candidates.end());
    std::vector<int> temp;
    Helper(target, 0, candidates, temp, res);
    return res;
   }

 private:
  bool Helper(int target,
              int index,
              std::vector<int> candidates,
              std::vector<int> temp,
              std::vector<std::vector<int> >& res) {
    if (target == 0) {
      res.push_back(temp);
      return false;
    } else if (target < 0) {
      return false;
    }
    for (unsigned i = index; i < candidates.size(); ++i) {
      if (i > index && candidates[i] == candidates[i - 1]) {
        continue;
      }
      temp.push_back(candidates[i]);
      if (!Helper(target - candidates[i], i, candidates, temp, res)) {
        break;
      }
      temp.pop_back();
    }
    return true;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
  }
  int target;
  scanf("%d", &target);
  Solution solution;
  std::vector<std::vector<int> > res = solution.CombinationSum(v, target);
  for (unsigned i = 0; i < res.size(); ++i) {
    for (unsigned j = 0; j < res[i].size(); ++j) {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
  return 0;
}
