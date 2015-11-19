#include <stdio.h>

#include <vector>
#include <set>

class Solution {
 public:
  std::vector<int> MaxSlidingWindow(std::vector<int>& nums, int k) {
    std::vector<int> result;
    if (nums.size() <= 0) return result;
    std::multiset<int> s(nums.begin(), nums.begin() + k - 1);
    for (size_t i = k - 1; i < nums.size(); ++i) {
      s.insert(nums[i]);
      result.push_back(*s.rbegin());
      s.erase(s.find(nums[i - k + 1]));
    }
    return result;
  }
};

int main() {
  int n, k;
  scanf("%d", &n);
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
  }
  scanf("%d", &k);

  Solution solution;
  v = solution.MaxSlidingWindow(v, k);
  for (size_t i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
  return 0;
}
