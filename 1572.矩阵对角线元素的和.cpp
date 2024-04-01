#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1572 lang=cpp
 *
 * [1572] 矩阵对角线元素的和
 */

// @lc code=start
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        int n = mat.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += mat[i][i];
            if (i != n - i - 1) {
                res += mat[i][n - i - 1];
            }
        }
        return res;
    }
};
// @lc code=end
