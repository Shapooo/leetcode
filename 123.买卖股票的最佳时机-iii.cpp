#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int size = prices.size();
        // vector<vector<int>> memo(size, vector<int>(size));
        int memo[2][4] {};
        memo[0][0] = memo[0][2] = -prices[0];
        for (int i = 1; i < size; ++i) {
            memo[i % 2][0] = max(memo[(i - 1) % 2][0], -prices[i]);
            memo[i % 2][1] = max(memo[(i - 1) % 2][1], memo[(i - 1) % 2][0] + prices[i]);
            memo[i % 2][2] = max(memo[(i - 1) % 2][2], memo[(i - 1) % 2][1] - prices[i]);
            memo[i % 2][3] = max(memo[(i - 1) % 2][3], memo[(i - 1) % 2][2] + prices[i]);
        }

        return memo[(size - 1) % 2][3];
    }
};
// @lc code=end
