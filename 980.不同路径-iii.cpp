#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=980 lang=cpp
 *
 * [980] 不同路径 III
 */

// @lc code=start
int a[4][2] = {
    { 1, 0 },
    { 0, 1 },
    { 0, -1 },
    { -1, 0 },
};
class Solution {
    vector<bitset<20>> bits = vector<bitset<20>>(20, bitset<20> {});
    int rec(vector<vector<int>>& grid, int x, int y)
    {
        // if (grid[x][y] == 2)
        if (bits[x][y] || grid[x][y] == -1 || grid[x][y] == 2 && depth != m * n - 1 - obstacle) {
            return 0;
        }
        cout << x << ' ' << y << ':' << grid[x][y] << ' ' << depth << endl;
        if (grid[x][y] == 2 && depth == m * n - 1 - obstacle) {
            return 1;
        }
        bits[x][y] = 1;
        depth += 1;
        int res = 0;
        for (int i = 0; i < 4; ++i) {
            if (x + a[i][0] >= 0 && x + a[i][0] < m && y + a[i][1] >= 0 && y + a[i][1] < n) {
                res += rec(grid, x + a[i][0], y + a[i][1]);
            }
        }
        depth -= 1;
        bits[x][y] = 0;
        return res;
    }
    int m, n;
    int depth = 0;
    int obstacle = 0;

public:
    int uniquePathsIII(vector<vector<int>>& grid)
    {
        m = grid.size(), n = grid[0].size();
        int x, y;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    x = i, y = j;
                } else if (grid[i][j] == -1) {
                    obstacle++;
                }
            }
        }
        return rec(grid, x, y);
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<vector<int>> grid { { 1, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 2, -1 } };
    grid = { { 1, 0, 0 }, { 0, 0, 0 }, { 0, 0, 2 } };
    cout << sol.uniquePathsIII(grid) << endl;
}