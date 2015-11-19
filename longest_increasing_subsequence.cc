#include <stdio.h>

#include <vector>
#include <algorithm>

class Solution {
 public:
  int LengthOfLIS(std::vector<int>& nums) {
    if (nums.size() <= 0) {
      return 0;
    }
    int max_len = 1;
    std::vector<int> v(nums.size(), 1);
    for (size_t i = 1; i < nums.size(); ++i) {
      for (size_t j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
        v[i] = std::max(v[j] + 1, v[i]);
        }
      }
      max_len = std::max(max_len, v[i]);
    }
    return max_len;
  }
};

int main() {
  int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
  std::vector<int> v(nums, nums + 8);
  Solution solution;
  int res = solution.LengthOfLIS(v);
  printf("%d\n", res);
  return 0;
}
