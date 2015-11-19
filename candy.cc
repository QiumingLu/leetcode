#include <stdio.h>
#include <vector>
#include <algorithm>

class Solution {
 public:
  int Candy(std::vector<int>& ratings) {
    int count = 0;
    int ratings_size = ratings.size();
    std::vector<int> res(ratings_size, 1);
    for (int i = 1; i < ratings_size; ++i) {
      if (ratings[i] > ratings[i - 1]) {
        res[i] = res[i - 1] + 1;
      }
    }
    for (int i = ratings_size - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        res[i] = std::max(res[i], res[i + 1] + 1);
      }
    }
    for (int i = 0; i < ratings_size; ++i) {
      count += res[i];
    }
    return count;
  }
};

int main() {
  int n;
  scanf("%d" , &n);
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
  }
  Solution solution;
  int res = solution.Candy(v);
  printf("%d\n", res);
  return 0;
}
