#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start
class Solution {
    int m, n;
    vector<int> ufs;
    int find(int n)
    {
        if (ufs[n] == n) {
            return n;
        }
        ufs[n] = find(ufs[n]);
        return ufs[n];
    }

    void merge(int a, int b)
    {
        int aa = find(a);
        int bb = find(b);
        if (aa == m * n || bb == m * n) {
            ufs[aa] = m * n;
            ufs[bb] = m * n;
        } else {
            ufs[aa] = bb;
        }
    }

    bool
    check_cord(int x, int y)
    {
        return x < n && x >= 0 && y < m && y >= 0;
    }
    void help(vector<vector<int>>& grid, int x, int y)
    {
        if (grid[x][y] == 1) {
            return;
        }
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            ufs[x * m + y] = m * n;
        }
        int delta[][2] = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };
        for (auto& v : delta) {
            int nx = x + v[0];
            int ny = y + v[1];
            if (check_cord(nx, ny) && grid[nx][ny] == 0) {
                merge(nx * m + ny, x * m + y);
            }
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid)
    {
        m = grid[0].size(), n = grid.size();
        ufs = vector<int>(m * n + 1);
        for (int i = 0; i <= m * n; ++i) {
            ufs[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                help(grid, i, j);
            }
        }
        int res {};
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < m - 1; ++j) {
                if (!grid[i][j] && ufs[i * m + j] == i * m + j) {
                    res++;
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
    vector<vector<int>> grid {
        { 0, 0, 1, 1, 0, 1, 0, 0, 1, 0 },
        { 1, 1, 0, 1, 1, 0, 1, 1, 1, 0 },
        { 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
        { 0, 1, 1, 0, 0, 0, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
        { 0, 1, 0, 1, 0, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
        { 1, 1, 1, 0, 0, 1, 0, 1, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 1, 0 }
    };
    printf("%d\n", sol.closedIsland(grid));
}