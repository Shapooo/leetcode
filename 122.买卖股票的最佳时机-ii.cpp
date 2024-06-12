#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int size = prices.size();
        int result = 0;
        for (int i = 1; i < size; ++i) {
            if (prices[i - 1] < prices[i]) {
                result += prices[i] - prices[i - 1];
            }
        }
        return result;
    }
};
// @lc code=end
