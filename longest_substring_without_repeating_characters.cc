#include <stdio.h>
#include <string.h>

#include <string>

class Solution {
 public:
  int LengthOfLongestSubstring(std::string s) {
    int max = 0, start = -1;
    int nums[256];
    memset(nums, -1, sizeof(nums));
    for (int i = 0; i < s.size(); ++i) {
      if (nums[s[i]] > start) {
       start = nums[s[i]];
      }
      nums[s[i]] = i;
      if (max < (i - start)) {
        max = i - start;
      }
    }
    return max;
  }
};

int main() {
  std::string s = "c";
  Solution solution;
  int result = solution.LengthOfLongestSubstring(s);
  printf("%d\n", result);
  return 0;
}
