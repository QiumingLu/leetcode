#include <stdio.h>
#include <vector>

class Solution {
 public:
  std::vector<int> GrayCode(int n) {
    std::vector<int> result;
    int size = 1 << n;
    for (int i = 0; i < size; ++i) {
      result.push_back((i >> 1) ^ i);
    }
    return result;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  Solution solution;
  std::vector<int> result = solution.GrayCode(n);
  for (size_t i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
