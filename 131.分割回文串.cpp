#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    bool _isPalindrome(string& s, int start, int end)
    {
        end--;
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s)
    {
        _helper(s, 0);
        return _ans;
    }
    void _helper(string& s, int start)
    {
        int size = s.size();
        if (start >= size) {
            _ans.push_back(_path);
            return;
        }
        for (int i = start + 1; i <= size; ++i) {
            if (_isPalindrome(s, start, i)) {
                _path.emplace_back(s, start, i - start);
                _helper(s, i);
                _path.pop_back();
            }
        }
    }
    vector<vector<string>> _ans {};
    vector<string> _path {};
};
// @lc code=end
