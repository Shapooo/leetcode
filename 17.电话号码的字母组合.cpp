#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
const string table[] = { "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz" };
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        if (!digits.size())
            return _ans;
        _helper(digits, 0);
        return _ans;
    }
    void _helper(string& digits, int start)
    {
        if (start == digits.size()) {
            _ans.push_back(_path);
            return;
        }
        for (auto& c : table[digits[start] - '2']) {
            _path.push_back(c);
            _helper(digits, start + 1);
            _path.pop_back();
        }
    }
    vector<string> _ans {};
    string _path {};
};
// @lc code=end
