#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1582 lang=cpp
 *
 * [1582] 二进制矩阵中的特殊位置
 */

// @lc code=start
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int result { 0 };
        for (int i = 0; i < m; ++i) {
            int index = -1;
            bool conflict = false;
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    if (index == -1) {
                        index = j;
                    } else {
                        conflict = true;
                        break;
                    }
                }
            }
            if (conflict || index == -1) {
                continue;
            }
            for (int k = 0; k < m; ++k) {
                if (mat[k][index] && k != i) {
                    conflict = true;
                    break;
                }
            }
            result += !conflict;
        }
        return result;
    }
};
// @lc code=end
