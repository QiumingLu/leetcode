#include <stdio.h>
#include <vector>

class Solution {
 public:
  int HIndex(std::vector<int>& citations) {
    int size = citations.size();
    int max = 0;
    for (int i = 0; i < size; ++i) {
      if (citations[i] >= size - i) {
        max = size - i;
        break;
      }
    }
    return max;
  }
};

int main() {
  int num[] = {0, 1, 3, 5, 6};
  std::vector<int> citations;
  citations.assign(num, num + 5);
  Solution solution;
  int res = solution.HIndex(citations);
  printf("%d\n", res);
  return 0;
}
