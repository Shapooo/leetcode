#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=3128 lang=cpp
 *
 * [3128] 直角三角形
 */

// @lc code=start
class Solution {
  public:
    long long numberOfRightTriangles(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row_cnts(n), col_cnts(m);
        for (int i = 0; i < n; ++i) {
            int cnt{};
            for (int j = 0; j < m; ++j) {
                cnt += grid[i][j];
            }
            row_cnts[i] = cnt;
        }
        for (int i = 0; i < m; ++i) {
            int cnt{};
            for (int j = 0; j < n; ++j) {
                cnt += grid[j][i];
            }
            col_cnts[i] = cnt;
        }
        long long res{};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    res += (row_cnts[i] - 1) * (col_cnts[j] - 1);
                }
            }
        }
        return res;
    }
};
// @lc code=end
