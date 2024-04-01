#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2017 lang=cpp
 *
 * [2017] 网格游戏
 */

// @lc code=start
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid)
    {
        int n = grid[0].size();
        vector<long long> pre(n + 1), suf(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + grid[1][i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1] + grid[0][i];
        }
        long long res = suf[0];
        for (int i = 0; i < n; ++i) {
            res = min(res, max(pre[i], suf[i + 1]));
        }
        return res;
    }
};
// @lc code=end
