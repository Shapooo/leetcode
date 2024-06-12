#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 *
 * [1475] 商品折扣后的最终价格
 */

// @lc code=start
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices)
    {
        int size = prices.size();
        int memo[size];
        vector<int> result(size);
        for (int i = size - 1; i >= 0; --i) {
            int index = i + 1;
            while (index != size) {
                if (prices[index] > prices[i]) {
                    index = memo[index];
                } else {
                    break;
                }
            }
            if (index != size) {
                result[i] = prices[i] - prices[index];
            } else {
                result[i] = prices[i];
            }
            memo[i] = index;
        }

        return result;
    }
};
// @lc code=end
