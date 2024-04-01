/*
 * @lc app=leetcode.cn id=2240 lang=cpp
 *
 * [2240] 买钢笔和铅笔的方案数
 */

// @lc code=start
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2)
    {
        long long res {};
        for (int i = 0; i <= total; i += cost1) {
            res += (total - i) / cost2 + 1;
        }
        return res;
    }
};
// @lc code=end
