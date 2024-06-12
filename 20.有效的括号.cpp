#include <stack>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s)
    {
        if (s.size() % 2) {
            return false;
        }
        stack<char> stk;
        for (auto i : s) {
            if (i == '(' || i == '[' || i == '{') {
                stk.push(i);
            } else if (!stk.empty()) {
                if (i == ']') {
                    if (stk.top() == '[') {
                        stk.pop();
                    } else {
                        return false;
                    }
                } else if (i == ')') {
                    if (stk.top() == '(') {
                        stk.pop();
                    } else {
                        return false;
                    }

                } else {
                    if (stk.top() == '{') {
                        stk.pop();
                    } else {
                        return false;
                    }
                }
            } else {
                return false;
            }
        }
        return stk.empty();
    }
};
// @lc code=end
