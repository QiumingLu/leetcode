#include <stdio.h>

#include <vector>
#include <string>

class Solution {
 public:
  std::vector<std::string> RestoreIpAddresses(std::string s) {
    std::vector<std::string> result;
    if (s.size() <= 3) { return result; }
    std::vector<std::string> v;
    SplitIpHelper(s, 0, v, result);
    return result;
  }

 private:
  void SplitIpHelper(const std::string& s, size_t index, 
                     std::vector<std::string>& v, 
                     std::vector<std::string>& result) {
    if (index == s.size() && v.size() == 4) {
      result.push_back(v[0] + '.' + v[1] + '.' + v[2] + '.' + v[3]);
      return;
    }
    if ((index != s.size() && v.size() == 4) || 
        (index >= s.size() && v.size() < 4)) {
      return;
    }

    for (size_t i = index; i < index + 3 && i < s.size(); ++i) {
      std::string t = s.substr(index, i - index + 1);
      int value = stoi(t);
      if (value > 255) { return; }
      v.push_back(t);
      SplitIpHelper(s, i + 1, v, result);
      v.pop_back();
      if (s[index] == '0') { return; }
    }
  }
};

int main() {
  std::string s = "25525511135";
  Solution solution;
  std::vector<std::string> result = solution.RestoreIpAddresses(s);
  for (size_t i = 0; i < result.size(); ++i) {
    printf("%s\n", result[i].c_str());
  }
  return 0;
}
