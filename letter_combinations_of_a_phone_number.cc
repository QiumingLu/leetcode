// Source : https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : Qiuming Lu
// Date   : 2015-09-02

/********************************************************************************** 
* 
* Given a digit string, return all possible letter combinations that the number could represent.
* 
* A mapping of digit to letters (just like on the telephone buttons) is given below.
* 
* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
* 
* Note:
* Although the above answer is in lexicographical order, your answer could be in any order you want.
* 
*               
**********************************************************************************/

#include <vector>
#include <string>

std::vector<std::string> letterCombinations(std::string digits) {
	int slen = digits.size();
	std::vector<std::string> res;

	if (slen <= 0) {
		return res;
	}
}