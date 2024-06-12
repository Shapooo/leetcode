#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */

// @lc code=start
class Solution {
public:
    int balancedStringSplit(string s)
    {
        int balance_count { 0 };
        int result { 0 };
        for (auto& c : s) {
            balance_count += c == 'R' ? 1 : -1;
            if (balance_count == 0) {
                ++result;
            }
        }
        return result;
    }
};
// @lc code=end
