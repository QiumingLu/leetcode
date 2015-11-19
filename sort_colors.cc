#include <stdio.h>

#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
void swap(T& t1, T& t2) {
  T t = t1;
  t1 = t2;
  t2 = t;
}

template <typename T>
void myfunction(T t) {
  std::cout << t;
}

class Solution {
 public:
  void SortColors(std::vector<int>& nums) {
    int begin = 0, end = nums.size() - 1;
    for (int i = 0; i <= end; ++i) {
      if (nums[i] == 0) {
        swap<int>(nums[i], nums[begin++]);
      } else if (nums[i] == 2) {
        swap<int>(nums[i--], nums[end--]);
      }
    }
  }
};

int main() {
  int nums[] = {0, 1, 2, 0, 0, 1, 2, 1, 0,2};
  std::vector<int> v(nums, nums + 10);
  Solution solution;
  solution.SortColors(v);
  for_each(v.begin(), v.end(), myfunction<int>);
  printf("\n");
  return 0;
}
