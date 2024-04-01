#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2596 lang=cpp
 *
 * [2596] 检查骑士巡视方案
 */

// @lc code=start
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid)
    {
        int n = grid.size();
        if (n == 3 || n == 4) {
            return false;
        }
        if (grid[0][0]) {
            return false;
        }
        vector<pair<int, int>> steps(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                steps[grid[i][j]] = { i, j };
            }
        }
        for (int i = 1; i < n * n; ++i) {
            int diffx = abs(steps[i].first - steps[i - 1].first);
            int diffy = abs(steps[i].second - steps[i - 1].second);
            if (!(diffx == 1 && diffy == 2 || diffx == 2 && diffy == 1)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

bool dfs(vector<vector<int>>& grid, int x, int y, int steps)
{
    int n = grid.size();
    if (steps == n * n) {
        return true;
    }
    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != -1) {
        return false;
    }
    grid[x][y] = steps;
    int step[8][2] = {
        { 1, 2 },
        { 2, 1 },
        { 1, -2 },
        { 2, -1 },
        { -1, 2 },
        { -2, 1 },
        { -1, -2 },
        { -2, -1 },
    };
    for (auto& v : step) {
        if (dfs(grid, x + v[0], y + v[1], steps + 1)) {
            return true;
        }
    }
    grid[x][y] = -1;
    return false;
}
int main()
{
    for (int i = 3; i <= 7; ++i) {
        vector<vector<int>> grid(i, vector<int>(i, -1));
        printf("%d %d\n", i, dfs(grid, 0, 0, 0));
    }
}