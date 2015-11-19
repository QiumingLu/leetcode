#include <stdio.h>
#include <vector>
#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<int> > CombinationSum2(
      std::vector<int>& candidates, 
      int target) {
    std::vector<std::vector<int> > result_vector;
    std::sort(candidates.begin(), candidates.end());
    std::vector<int> v;
    Helper(target, result_vector, 0, v, candidates);
    return result_vector;
  }

 private:
  bool Helper(int target, std::vector<std::vector<int> >& result_vector,
              int index, 
              std::vector<int> v,
              std::vector<int> candidates) {
    if (target == 0) {
      result_vector.push_back(v);
      return false;
    } else if(target < 0) {
      return false;
    }

    for (int i = index; i < candidates.size(); ++i) {
      if (i > index && candidates[i] == candidates[i - 1]) {
        continue;
      }
      v.push_back(candidates[i]);
      if (!Helper(target - candidates[i], result_vector, i + 1, v, candidates)) {
        break;
      }
      v.pop_back();
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
  std::vector<std::vector<int> > res_v = solution.CombinationSum2(v, target);
  for (unsigned i = 0; i < res_v.size(); ++i) {
    for (unsigned j = 0; j < res_v[i].size(); ++j) {
      printf("%d ", res_v[i][j]);
    }
    printf("\n");
  }
  return 0;
}
