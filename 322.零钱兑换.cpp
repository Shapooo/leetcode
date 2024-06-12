#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> memo(amount + 1, -1);
        memo[0] = 0;
        for (auto& n : coins) {
            for (int i = n; i <= amount; ++i) {
                if (memo[i - n] != -1) {
                    if (memo[i] == -1) {
                        memo[i] = memo[i - n] + 1;
                    } else {
                        memo[i] = min(memo[i], memo[i - n] + 1);
                    }
                }
            }
        }
        return memo[amount];
    }
};
// @lc code=end
