/*
 * @lc app=leetcode.cn id=2544 lang=cpp
 *
 * [2544] 交替数字和
 */

// @lc code=start
class Solution {
public:
    int alternateDigitSum(int n)
    {
        int len = 0;
        int res = 0;
        while (n) {
            res += len % 2 ? n % 10 : -n % 10;
            n /= 10;
            len += 1;
        }
        if (len % 2) {
            res *= -1;
        }

        return res;
    }
};
// @lc code=end
