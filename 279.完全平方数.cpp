#include <cmath>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n)
    {
        int m = sqrt(n);
        vector<int> memo(n + 1, -1);
        memo[0] = 0;
        for (int i = 1; i <= m; ++i) {
            int num = i * i;
            for (int j = num; j <= n; ++j) {
                if (memo[j - num] != -1) {
                    if (memo[j] == -1) {
                        memo[j] = memo[j - num] + 1;
                    } else {
                        memo[j] = min(memo[j], memo[j - num] + 1);
                    }
                }
            }
        }
        return memo[n];
    }
};
// @lc code=end
