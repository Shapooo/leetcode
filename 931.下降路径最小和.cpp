#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> dp = matrix[0];
        for (int j = 1; j < n; ++j) {
            vector<int> t(m, 0);
            for (int i = 0; i < m; ++i) {
                auto tmp = dp[i];
                if (i > 0) {
                    tmp = min(tmp, dp[i - 1]);
                }
                if (i < m - 1) {
                    tmp = min(tmp, dp[i + 1]);
                }
                t[i] = tmp + matrix[j][i];
            }
            dp = t;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
// @lc code=end
