#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1219 lang=cpp
 *
 * [1219] 黄金矿工
 */

// @lc code=start
class Solution {
    int m, n;
    int dfs(vector<vector<int>>& grid, int x, int y)
    {
        if (x < 0 || x >= n || y < 0 || y >= m || !grid[x][y]) {
            return 0;
        }
        int res = 0;
        int delta[][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        int tmp = grid[x][y];
        grid[x][y] = 0;
        for (auto& v : delta) {
            int nx = x + v[0];
            int ny = y + v[1];
            res = max(res, dfs(grid, nx, ny));
        }
        grid[x][y] = tmp;
        return res + tmp;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid)
    {
        n = grid.size(), m = grid[0].size();
        int res {};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<vector<int>> grid { { 0, 6, 0 }, { 5, 8, 7 }, { 0, 9, 0 } };
    sol.getMaximumGold(grid);
}