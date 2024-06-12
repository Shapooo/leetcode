#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        string s {};
        vector<string> result {};
        backtrace(s, result, n, 0);
        return result;
    }
    void backtrace(string& s, vector<string>& result, int n, int remain)
    {
        if (!n) {
            if (remain) {
                s.append(string(remain, ')'));
            }
            result.push_back(s);
            s.erase(s.size() - remain, remain);
            return;
        }

        s.push_back('(');
        backtrace(s, result, n - 1, remain + 1);
        s.pop_back();
        if (remain) {
            s.push_back(')');
            backtrace(s, result, n, remain - 1);
            s.pop_back();
        }
    }
};
// @lc code=end
