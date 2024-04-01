/*
 * @lc app=leetcode.cn id=2582 lang=cpp
 *
 * [2582] 递枕头
 */

// @lc code=start
class Solution {
public:
    int passThePillow(int n, int time)
    {
        int pass = time / (n - 1), idx = time % (n - 1);
        return pass % 2 ? n - idx : idx + 1;
    }
};
// @lc code=end
