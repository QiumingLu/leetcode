#include <stdio.h>
#include <vector>
#include <functional>
#include <algorithm>

class Solution {
 public:
  int HIndex(std::vector<int>& citations) {
    std::sort(citations.begin(), citations.end(), std::greater<int>());
    int size = citations.size();
    int max = 0;
    for (int i = 0; i < size; ++i) {
      if (citations[i] >= i + 1) {
        max = i + 1;
      } else {
        break;
      }
    }
    return max;
  }
};

int main() {
  std::vector<int> citations;
  int num[] = {3, 0, 6, 1, 5};
  citations.assign(num, num + 5);
  Solution solution;
  int res = solution.HIndex(citations);
  printf("%d\n", res);
  return 0;
}
