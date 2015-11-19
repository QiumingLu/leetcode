#include <stdio.h>

#include <vector>
#include <algorithm>

class Solution {
 public:
  bool CanJump(std::vector<int>& nums) {
    int last = 0, temp = 0;
    for (int i = 0; i < static_cast<int> (nums.size()); ++i) {
      if (i > last) {
        if (i > temp) {
          return false;
        }
        last = temp;
      }
      temp = std::max(temp, i + nums[i]);
    }
    return true;
  }
};

int main() {
  int A1[] = {2, 3, 1, 1, 4};
  int A2[] = {3, 2, 1, 0, 4};
  std::vector<int> v1(A1, A1 + 5);
  std::vector<int> v2(A2, A2 + 5);
  Solution solution;
  bool res1 = solution.CanJump(v1);
  bool res2 = solution.CanJump(v2);
  printf("%d %d\n", res1, res2);
  return 0;
}
