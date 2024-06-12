#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int result = 0;
        int size = cost.size();
        vector<int> mincost(size + 1);
        int a = 0, b = 0;
        int min_cost = 0;
        for (int i = 2; i <= size; ++i) {
            min_cost = min(a + cost[i - 2], b + cost[i - 1]);
            a = b;
            b = min_cost;
        }
        return min_cost;
    }
};
// @lc code=end
