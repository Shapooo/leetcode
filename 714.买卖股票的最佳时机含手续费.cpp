#include <limits>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int result = 0;
        prices.push_back(-1);
        int size = prices.size();
        int buy = numeric_limits<int>::max(), sell = -1;

        for (int i = 0; i < size; ++i) {
            sell = max(prices[i], sell);
            if (prices[i] + fee <= sell) {
                result += max(sell - buy - fee, 0);
                buy = prices[i];
                sell = prices[i];
            } else {
                buy = min(prices[i], buy);
            }
        }

        return result;
    }
};
// @lc code=end
