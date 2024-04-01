#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=2609 lang=cpp
 *
 * [2609] 最长平衡子字符串
 */

// @lc code=start
class Solution {
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int res {}, zero {}, one {}, last {};
        int n = s.size();
        for (auto c : s) {
            if (c == '0') {
                if (last == 1) {
                    zero = 0;
                    one = 0;
                    last = 0;
                }
                zero++;
            } else {
                if (last == 0) {
                    one = 0;
                    last = 1;
                }
                one++;
                res = max(res, min(zero, one) * 2);
            }
        }
        return res;
    }
};
// @lc code=end
