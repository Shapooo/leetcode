/*
 * @lc app=leetcode.cn id=2591 lang=cpp
 *
 * [2591] 将钱分给最多的儿童
 */

// @lc code=start
class Solution {
public:
    int distMoney(int money, int children)
    {
        if (children * 8 == money) {
            return children;
        } else if (children * 8 < money) {
            return children - 1;
        } else if (children > money) {
            return -1;
        }
        int res = (money - children) / 7;
        if (children - res == 1 && money - res * 8 == 4) {
            return res - 1;
        } else {
            return res;
        }
    }
};
// @lc code=end
