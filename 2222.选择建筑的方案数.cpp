#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=2222 lang=cpp
 *
 * [2222] 选择建筑的方案数
 */

// @lc code=start
class Solution {
public:
    long long numberOfWays(string s)
    {
        long long dp[6] = {};
        for (auto c : s) {
            if (c == '0') {
                dp[0]++;
                dp[2] += dp[1];
                dp[4] += dp[3];
            } else {
                dp[1] += dp[0];
                dp[3]++;
                dp[5] += dp[4];
            }
        }
        return dp[2] + dp[5];
    }
};
// @lc code=end
