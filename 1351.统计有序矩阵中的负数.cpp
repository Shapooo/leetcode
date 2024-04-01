#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1351 lang=cpp
 *
 * [1351] 统计有序矩阵中的负数
 */

// @lc code=start
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int res {};
        for (auto& v : grid) {
            for (auto& n : v) {
                if (n < 0) {
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
