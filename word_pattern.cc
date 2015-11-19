#include <map>
#include <set>
#include <string>
#include <stdio.h>

class Solution {
 public:
  bool WordPattern(std::string pattern, std::string str) {
    std::map<char, std::string> m;
    std::set<std::string> s;
    int i = 0, j = 0, begin;
    int pattern_size = pattern.size(), str_size = str.size();
    while(i < pattern_size && j < str_size) {
      begin = j;
      while(str[j] != ' ' && j < str_size) {
        ++j;
      }
      std::string strTemp;
      strTemp = str.substr(begin, j - begin);
      if (m.find(pattern[i]) != m.end()) {
        if (m[pattern[i]] != strTemp) {
          return false;
        }
      } else {
        if (s.find(strTemp) != s.end()) {
          return false;
        }
        m.insert(make_pair(pattern[i], strTemp));
        s.insert(strTemp);
      }
      ++i;
      ++j;
    }
    if (i < pattern_size || j < str_size) {
      return false;
    }
    return true;
  }
};

int main() {
  std::string pattern = "abba";
  std::string str = "dog cat cat dog";
  Solution solution;
  bool res = solution.WordPattern(pattern, str);
  printf("%d\n", res);
  return 0;
}
