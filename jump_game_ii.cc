#include <stdio.h>
#include <vector>
#include <algorithm>

class Solution {
 public:
  int Jump(std::vector<int>& nums) {
    int temp = 0, last = 0, result = 0;
    for (int i = 0; i < static_cast<int> (nums.size()); ++i) {
      if (i > last) {
        ++result;
        last = temp;
      }
      temp = std::max(temp, i + nums[i]);
    }

    return result;
  }
};

int main() {
  int A[] = {2, 3, 1, 1, 4};
  std::vector<int> v(A, A + 5);
  Solution solution;
  int result = solution.Jump(v);
  printf("%d\n", result);
  return 0;
}
