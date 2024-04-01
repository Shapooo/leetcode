#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1905 lang=cpp
 *
 * [1905] 统计子岛屿
 */

// @lc code=start
class Solution {
    int m, n;
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y)
    {
        if (x < 0 || x >= m || y < 0 || y >= n || !grid2[x][y]) {
            return true;
        }
        int delta[4][2] = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };
        bool res = grid1[x][y];
        grid2[x][y] = 0;
        for (auto& v : delta) {
            res &= dfs(grid1, grid2, x + v[0], y + v[1]);
        }
        return res;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        m = grid1.size(), n = grid1[0].size();
        int res {};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j]) {
                    res += dfs(grid1, grid2, i, j);
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<vector<int>> grid1 = { { 1, 1, 1, 0, 0 }, { 0, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 }, { 1, 1, 0, 1, 1 } }, grid2 = { { 1, 1, 1, 0, 0 }, { 0, 0, 1, 1, 1 }, { 0, 1, 0, 0, 0 }, { 1, 0, 1, 1, 0 }, { 0, 1, 0, 1, 0 } };
    sol.countSubIslands(grid1, grid2);
}