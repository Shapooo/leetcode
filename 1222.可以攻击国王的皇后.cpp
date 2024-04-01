#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1222 lang=cpp
 *
 * [1222] 可以攻击国王的皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king)
    {
        int direct[8][2] = {
            { 1, 0 },
            { 0, 1 },
            { 1, -1 },
            { 1, 1 },
            { -1, 0 },
            { 0, -1 },
            { -1, -1 },
            { -1, 1 },
        };
        int qs[8][8] {};
        for (auto& q : queens) {
            qs[q[0]][q[1]] = 1;
        }
        int x = king[0], y = king[1];
        vector<vector<int>> res {};
        for (auto& v : direct) {
            for (int i = 1;; ++i) {
                int xx = x + v[0] * i;
                int yy = y + v[1] * i;
                if (xx < 0 || xx >= 8 || yy < 0 || yy >= 8) {
                    break;
                }
                if (qs[xx][yy]) {
                    res.emplace_back(vector<int> { xx, yy });
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
