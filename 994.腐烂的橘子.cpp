#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
    int m, n;
    void rot(vector<vector<int>>& grid, vector<int>& rotten, int cord)
    {
        int x = cord >> 16, y = cord & 0xffff;
        int di[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
        for (auto const& d : di) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                grid[nx][ny] = 2;
                rotten.push_back((nx << 16) | ny);
            }
        }
    }

public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        vector<int> rotten {};
        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    rotten.push_back((i << 16) | j);
                }
            }
        }

        int res {};
        while (true) {
            vector<int> tmp {};
            for (auto const& r : rotten) {
                rot(grid, tmp, r);
            }
            if (tmp.empty()) {
                break;
            } else {
                rotten = std::move(tmp);
                ++res;
            }
        }

        for (auto const& g : grid) {
            for (auto const& c : g) {
                if (c == 1) {
                    return -1;
                }
            }
        }
        return res;
    }
};
// @lc code=end
