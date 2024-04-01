#include <cstdio>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1249 lang=cpp
 *
 * [1249] 移除无效的括号
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        string res {};
        int stk {};
        int n = s.size();
        int last = 0;
        int r {};
        for (auto c : s) {
            if (c == ')') {
                r++;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                if (stk < r) {
                    stk++;
                    res.push_back('(');
                }
            } else if (s[i] == ')') {
                if (stk) {
                    r--;
                    stk--;
                    res.push_back(')');
                } else {
                    r--;
                }
            } else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    string s = "(()";
    printf("%s\n", sol.minRemoveToMakeValid(s).c_str());
    s = "lee(t(c)o)de)";
    printf("%s\n", sol.minRemoveToMakeValid(s).c_str());
    s = "a)b(c)d";
    printf("%s\n", sol.minRemoveToMakeValid(s).c_str());
    s = "))((";
    printf("%s\n", sol.minRemoveToMakeValid(s).c_str());
}