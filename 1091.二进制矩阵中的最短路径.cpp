#include <cstdio>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
class Solution {
    bool check(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& grid)
    {
        return x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && !grid[x][y];
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();
        if (grid[0][0]) {
            return -1;
        }
        if (n == 1) {
            return 1;
        }
        queue<pair<int, int>> que {};
        vector<vector<int>> dist(n, vector<int>(n));
        que.emplace(0, 0);
        dist[0][0] = 1;
        int dir[][2] = { { 1, 1 }, { 1, 0 }, { 1, -1 }, { -1, 1 }, { -1, 0 }, { -1, -1 }, { 0, 1 }, { 0, -1 } };
        while (!que.empty()) {
            auto co = que.front();
            que.pop();
            int d = dist[co.first][co.second];
            for (auto& v : dir) {
                int x = co.first + v[0];
                int y = co.second + v[1];
                if (check(x, y, n, dist, grid)) {
                    if (x == n - 1 && y == n - 1) {
                        return d + 1;
                    }
                    que.emplace(x, y);
                    dist[x][y] = d + 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<vector<int>> grid = { { 0 } };
    printf("%d ", sol.shortestPathBinaryMatrix(grid));
}