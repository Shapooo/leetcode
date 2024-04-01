#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1267 lang=cpp
 *
 * [1267] 统计参与通信的服务器
 */

// @lc code=start
class Solution {
public:
    int countServers(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<int> row_cnt(n, 0), col_cnt(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    row_cnt[i]++;
                    col_cnt[j]++;
                }
            }
        }
        int res {};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] && (row_cnt[i] > 1 || col_cnt[j] > 1)) {
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
