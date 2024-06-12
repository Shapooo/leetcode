#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        // int low = 10e4;
        // int high = -1;
        // int result = 0;
        // for (auto &i : prices) {
        //   result = max(result, i - low);
        //   low = min(i, low);
        // }
        // return result;
        int size = prices.size();
        vector<pair<int, int>> memo(size);
        memo[0].first = -prices[0];
        memo[0].second = 0;
        for (int i = 1; i < size; ++i) {
            memo[i].first = max(memo[i - 1].first, -prices[i]);
            memo[i].second = max(memo[i - 1].first + prices[i], memo[i - 1].second);
        }
        return memo[size - 1].second;
    }
};
// @lc code=end
