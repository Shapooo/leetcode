#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int size = prices.size();
        if (size == 1) {
            return 0;
        }
        if (size == 2) {
            return max(0, prices[1] - prices[0]);
        }
        int memo[3][2] {};
        memo[0][0] = -prices[0];
        memo[1][0] = max(-prices[1], -prices[0]);
        memo[1][1] = max(0, prices[1] - prices[0]);
        for (int i = 2; i < size; ++i) {
            memo[i % 3][0] = max(memo[(i - 1) % 3][0], memo[(i - 2) % 3][1] - prices[i]);
            memo[i % 3][1] = max(memo[(i - 1) % 3][1], memo[(i - 1) % 3][0] + prices[i]);
        }

        return memo[(size - 1) % 3][1];
    }
};
// @lc code=end
