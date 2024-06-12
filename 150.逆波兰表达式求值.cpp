#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> stk;
        for (auto& i : tokens) {
            int tmp = 0;
            if (i.size() > 1) {
                tmp = stoi(i);
            } else {
                switch (i[0]) {
                case '+': {
                    auto tmp1 = stk.top();
                    stk.pop();
                    auto tmp2 = stk.top();
                    stk.pop();
                    tmp = tmp1 + tmp2;
                    break;
                }
                case '-': {
                    auto tmp1 = stk.top();
                    stk.pop();
                    auto tmp2 = stk.top();
                    stk.pop();
                    tmp = tmp2 - tmp1;
                    break;
                }
                case '*': {
                    auto tmp1 = stk.top();
                    stk.pop();
                    auto tmp2 = stk.top();
                    stk.pop();
                    tmp = tmp1 * tmp2;
                    break;
                }
                case '/': {
                    auto tmp1 = stk.top();
                    stk.pop();
                    auto tmp2 = stk.top();
                    stk.pop();
                    tmp = tmp2 / tmp1;
                    break;
                }
                default:
                    tmp = stoi(i);
                    break;
                }
            }
            stk.push(tmp);
        }
        return stk.top();
    }
};
// @lc code=end
