#include <stdio.h>
#include <vector>

class Solution {
 public:
  int FindPeakElement(std::vector<int>& nums) {
    int index = 0;
    for (unsigned i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        index = i;
      } else {
        return index;
      }
    }
    return index;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
  }
  Solution solution;
  int res = solution.FindPeakElement(v);
  printf("%d\n", res);
  return 0;
}
