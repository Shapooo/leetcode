#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n)
    {
        vector<int> memo(n);
        memo[1] = 1;
        for (int i = 2; i < n; ++i) {
            int m = i;
            for (int j = 1; j <= i / 2; ++j) {
                m = max(m, memo[j] * memo[i - j]);
            }
            memo[i] = m;
        }
        int result = 0;
        for (int i = 1; i <= n / 2; ++i) {
            result = max(result, memo[i] * memo[n - i]);
        }
        return result;
    }
};
// @lc code=end
