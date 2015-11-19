#include <stdio.h>

#include <string>
#include <vector>
#include <unordered_map>

class Solution {
 public:
  std::vector<int> FindSubstring(std::string s, 
                                 std::vector<std::string>& words) {
    std::vector<int> result;
    if (s.size() <= 0 || words.size() <= 0) {
      return result;
    }

    std::unordered_map<std::string, int> words_map;
    for (std::vector<std::string>::iterator it = words.begin(); 
         it != words.end(); ++it) {
      if (words_map.find(*it) != words_map.end()) {
        ++words_map[*it];
      } else {
        words_map[*it] = 1;
      }
    }
    
    int word_length = words[0].size();
    int s_length = s.size(), words_count = words.size();
    
    for (int i = 0; i < word_length; ++i) {
      int winleft = i;
      int count = 0;
      std::unordered_map<std::string, int> find_map;
      for (int j = i; j <= (s_length - word_length); j += word_length) {
        std::string temp = s.substr(j, word_length);
        
        if (words_map.find(temp) == words_map.end()) {
          winleft = j + word_length;
          count = 0;
          find_map.clear();
          continue;
        }

        if (find_map.find(temp) == find_map.end()) {
            find_map[temp] = 1;
        } else {
          ++find_map[temp];
          if (find_map[temp] > words_map[temp]) {
            std::string t;
            do {
              t = s.substr(winleft, word_length);
              --count;
              --find_map[t];
              winleft += word_length;
            } while (t != temp);
          }
        }
        ++count;

        if (count == words_count) {
          result.push_back(winleft);
          std::string t = s.substr(winleft, word_length);
          --find_map[t];
          winleft += word_length;
          --count;
        }
      }
    }
    return result;
  }
};

int main() {
  std::string s = "barfoothefoobarman";
  std::vector<std::string> v;
  v.push_back("foo");
  v.push_back("bar");
  Solution solution;
  std::vector<int> result = solution.FindSubstring(s, v);
  printf("[");
  std::vector<int>::iterator it;
  for (it= result.begin(); it != result.end() - 1; ++it) {
    printf("%d, ", *it);
  }
  printf("%d]\n", *it);
  return 0;
}
