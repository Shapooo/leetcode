#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1003 lang=cpp
 *
 * [1003] 检查替换后的词是否有效
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s)
    {
        string stk {};
        for (auto&& c : s) {
            switch (c) {
            case 'a':
                stk.push_back('a');
                break;
            case 'b':
                if (!stk.empty() && stk.back() == 'a') {
                    stk.back() = 'b';
                } else {
                    return false;
                }
                break;
            default:
                if (!stk.empty() && stk.back() == 'b') {
                    stk.pop_back();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
// @lc code=end
