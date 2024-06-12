#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        int size = prices.size();
        if (!size || !k) {
            return 0;
        }
        vector<int> memo[2] = { vector<int>(k * 2), vector<int>(k * 2) };
        for (int i = 0; i < k * 2; i += 2) {
            memo[0][i] = -prices[0];
        }
        for (int i = 1; i < size; ++i) {
            memo[i % 2][0] = max(memo[(i - 1) % 2][0], -prices[i]);
            memo[i % 2][1] = max(memo[(i - 1) % 2][1], memo[(i - 1) % 2][0] + prices[i]);
            for (int j = 1; j < k; ++j) {
                memo[i % 2][j * 2] = max(memo[(i - 1) % 2][j * 2],
                    memo[(i - 1) % 2][j * 2 - 1] - prices[i]);
                memo[i % 2][j * 2 + 1] = max(memo[(i - 1) % 2][j * 2 + 1],
                    memo[(i - 1) % 2][j * 2] + prices[i]);
            }
        }
        return memo[(size - 1) % 2][k * 2 - 1];
    }
};
// @lc code=end
