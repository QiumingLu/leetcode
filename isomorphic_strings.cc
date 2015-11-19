#include <stdio.h>
#include <string>
#include <map>

class Solution {
 public:
  bool Isomorphic(std::string s, std::string t) {
    int s_size = s.size(), t_size = t.size();
    if (s_size != t_size) {
      return false;
    }

    std::map<char, int> m1;
    std::map<char, int> m2;
    for (int i = 0; i < s_size; ++i) {
      std::map<char, int>::iterator it1 = m1.find(s[i]);
      std::map<char, int>::iterator it2 = m2.find(t[i]);
      if (it1 != m1.end() && it2 != m2.end()) {
        if (it1->second != it2->second) {
          return false;
        }
      } else if(it1 == m1.end() && it2 == m2.end()) {
        m1.insert(std::make_pair(s[i], i));
        m2.insert(std::make_pair(t[i], i));
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  std::string s = "egg";
  std::string t = "add";
  Solution solution;
  bool res = solution.Isomorphic(s, t);
  printf("%d\n", res);
  return 0;
}
