#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */

// @lc code=start
class Solution {
    void rec(int n, vector<vector<int>>& neighbors, vector<int>& colors)
    {
        bool occupied_color[4] {};
        for (auto&& i : neighbors[n]) {
            if (colors[i]) {
                occupied_color[colors[i] - 1] = true;
            }
        }
        for (int i = 0; i < 4; ++i) {
            if (occupied_color[i] == 0) {
                colors[n] = i + 1;
            }
        }
        for (auto&& i : neighbors[n]) {
            if (colors[i] == 0) {
                rec(i, neighbors, colors);
            }
        }
    }

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths)
    {
        vector<int> res(n);
        vector<vector<int>> neighbors(n);
        for (auto&& p : paths) {
            neighbors[p[0] - 1].push_back(p[1] - 1);
            neighbors[p[1] - 1].push_back(p[0] - 1);
        }

        for (size_t i = 0; i < n; i++) {
            if (res[i] == 0)
                rec(i, neighbors, res);
        }

        return res;
    }
};
// @lc code=end
