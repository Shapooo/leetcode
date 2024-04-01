/*
 * @lc app=leetcode.cn id=1281 lang=cpp
 *
 * [1281] 整数的各位积和之差
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n)
    {
        int prod { 1 }, sum {};
        while (n) {
            int rem = n % 10;
            prod *= rem;
            sum += rem;
            n /= 10;
        }
        return prod - sum;
    }
};
// @lc code=end
