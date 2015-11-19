#include <vector>
#include <string>
#include <iostream>

class Solution {
 public:
  std::vector<std::string> AddOperators(std::string num, int target) {
    std::vector<std::string> res_vector;
    Helper(target, res_vector, num, "", 0, 0);
    return res_vector;
  }
  
 private:
  void Helper(int target,
              std::vector<std::string>& res_vector,
              const std::string& num,  
              std::string res_string,
              long long current_result, 
              long long previous_num) {
    if (current_result == target && num.size() == 0) {
      res_vector.push_back(res_string);
      return;
    }
  
    for (unsigned i = 0; i < num.size(); ++i) {
      std::string current_string = num.substr(0, i + 1);
      if (current_string.size() > 1 && current_string[0] == '0') {
        return;
      }
      std::string next_string = num.substr(i + 1);
      if (res_string.size() > 0) {
        Helper(
            target, 
            res_vector, 
            next_string, 
            res_string + '+' + current_string, 
            current_result + stoll(current_string),
            stoll(current_string));
        Helper(
            target, 
            res_vector, 
            next_string, 
            res_string + '-' + current_string,
            current_result - stoll(current_string),
            -stoll(current_string));
        Helper(
            target, 
            res_vector, 
            next_string, 
            res_string + '*' + current_string,
            (current_result - previous_num) + (previous_num * stoll(current_string)),
            previous_num * stoll(current_string));
      } else {
        Helper(
            target, 
            res_vector,
            next_string, 
            current_string, 
            stoll(current_string), 
            stoll(current_string));
      }
    }
  }
};

int main() {
  std::string num;
  int target;
  std::cin >> num;
  std::cin >> target;
  Solution solution;
  std::vector<std::string> v = solution.AddOperators(num, target);
  std::vector<std::string>::iterator it;
  for (it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << std::endl;
  }
  return 0;
}
