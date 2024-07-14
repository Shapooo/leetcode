#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=807 lang=cpp
 *
 * [807] 保持城市天际线
 */

// @lc code=start
class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> row_max(n), col_max(n);
        for (int i = 0; i < n; ++i)
        {
            row_max[i] = *max_element(grid[i].begin(), grid[i].end());
        }
        for (int i = 0; i < n; ++i)
        {
            int m = grid[0][i];
            for (int j = 0; j < n; ++j)
            {
                m = max(m, grid[j][i]);
            }
            col_max[i] = m;
        }
        int res{};
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                res += min(row_max[i], col_max[j]) - grid[i][j];
            }
        }
        return res;
    }
};
// @lc code=end
