// Source : https://leetcode.com/problems/happy-number/
// Author : Qiuming Lu
// Date   : 2015-09-02

/********************************************************************************** 
 * 
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with any positive integer, 
 * replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 
 * (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this 
 * process ends in 1 are happy numbers.
 * 
 * Example: 19 is a happy number
 * 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * Credits:Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }
        
        std::set<int> s;
        s.insert(n);
        
        while (n != 1) {
            n = squares(n);
            
            if (s.find(n) != s.end()) {
                return false;
            }
            
            s.insert(n);
        }
        
        return true;
    }
    
private:
    int squares(int n) {
        int res = 0;
        int sq;
        while (n > 0) {
            sq = n % 10;
            res += sq * sq;
            n /= 10;
        }
        return res;
    }
};

