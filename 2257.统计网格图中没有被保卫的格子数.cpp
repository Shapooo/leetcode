#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2257 lang=cpp
 *
 * [2257] 统计网格图中没有被保卫的格子数
 */

// @lc code=start
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        vector<vector<int>> map(m, vector<int>(n));
        for (auto& w : walls) {
            map[w[0]][w[1]] = 1;
        }
        for (auto& g : guards) {
            map[g[0]][g[1]] = 2;
        }
        int res = guards.size() + walls.size();
        for (auto& g : guards) {
            for (int i = g[0] + 1, j = g[1]; i < m && map[i][j] <= 0; ++i) {
                if (!map[i][j]) {
                    map[i][j] = -1;
                    res += 1;
                }
            }
            for (int i = g[0] - 1, j = g[1]; i >= 0 && map[i][j] <= 0; --i) {
                if (!map[i][j]) {
                    map[i][j] = -1;
                    res += 1;
                }
            }
            for (int i = g[0], j = g[1] + 1; j < n && map[i][j] <= 0; ++j) {
                if (!map[i][j]) {
                    map[i][j] = -1;
                    res += 1;
                }
            }
            for (int i = g[0], j = g[1] - 1; j >= 0 && map[i][j] <= 0; --j) {
                if (!map[i][j]) {
                    map[i][j] = -1;
                    res += 1;
                }
            }
        }
        return n * m - res;
    }
};
// @lc code=end

int main()
{
    int m = 1, n = 100000;
    vector<vector<int>> guards = {};
    vector<vector<int>> wall { { 0, 0 } };
    m = 4, n = 6;
    guards = { { 0, 0 }, { 1, 1 }, { 2, 3 } };
    wall = { { 0, 1 }, { 2, 2 }, { 1, 4 } };
    Solution sol {};
    sol.countUnguarded(m, n, guards, wall);
}
