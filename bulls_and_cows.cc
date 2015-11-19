#include <stdio.h>
#include <assert.h>

#include <string>

class Solution {
 public:
  std::string GetHint(std::string secret, std::string guess) {
    assert(guess.size() == secret.size());
    int right = 0, wrong = 0;
    int nums[10] = {0};
    for (size_t i = 0; i < secret.size(); ++i) {
      if (guess[i] == secret[i]) {
        ++right;
      } else {
        int value = secret[i] - '0';
        ++nums[value];
      }
    }
    for (size_t i = 0; i < guess.size(); ++i) {
      int value = guess[i] - '0';
      if (guess[i] != secret[i] && nums[value] != 0) {
        ++wrong;
        --nums[value];
      }
    }

    return  std::to_string(right) + 'A' + std::to_string(wrong) + 'B';
  }
};

int main() {
  std::string s = "1807";
  std::string g = "7810";
  Solution solution;
  std::string res = solution.GetHint(s, g);
  printf("%s\n", res.c_str());
  return 0;
}
