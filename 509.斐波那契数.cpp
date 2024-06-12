/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n)
    {
        if (n == 0 || n == 1)
            return n;
        int a = 0, b = 1;
        for (int i = 1; i < n; ++i) {
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        return b;
    }
};
// @lc code=end
