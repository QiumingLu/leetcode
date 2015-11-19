#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>

class Solution {
 public:
  int Calculate(std::string s) {
    std::queue<int> num_queue;
    std::queue<char> sign_queue;
    int num = 0;
    int todo_num = 0;
    char todo_sign = 0;
    for (char c : s) {
      if (isdigit(c)) {
        num = num * 10 + c -'0';
      } else if (c == '+' || c == '-') {
        if (todo_sign == '*') {
          num = todo_num * num;
          todo_sign = 0;
        } else if (todo_sign == '/') {
          num = todo_num / num;
          todo_sign = 0;
        }
        num_queue.push(num);
        sign_queue.push(c);
        num = 0;
      } else if (c == '*' || c == '/') {
        if (todo_sign == '*') {
          todo_num *= num; 
        } else if (todo_sign == '/') {
          todo_num /= num;
        } else {
          todo_num = num;
        }
        todo_sign = c;
        num = 0;
      }
    }
    if (todo_sign == '*') {
      num = todo_num * num;
    } else if (todo_sign == '/') {
      num = todo_num / num;
    }

    num_queue.push(num);

    int a = num_queue.front();
    num_queue.pop();
    while (!num_queue.empty()) {
      int b = num_queue.front();
      num_queue.pop();
      char sign = sign_queue.front();
      sign_queue.pop();
      if (sign == '+') {
        a += b;
      }
      if (sign == '-') {
        a -= b;
      }
    }
    return a;
  }
};

int main() {
  std::string s;
  std::cin >> s;
  Solution solution;
  int res = solution.Calculate(s);
  printf("%d\n", res);
  return 0;
}
