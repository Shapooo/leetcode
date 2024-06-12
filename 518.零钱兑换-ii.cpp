#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        vector<int> memo(amount + 1);
        memo[0] = 1;
        for (auto& i : coins) {
            for (int j = i; j <= amount; ++j) {
                memo[j] += memo[j - i];
            }
        }
        return memo[amount];
    }
};
// @lc code=end
