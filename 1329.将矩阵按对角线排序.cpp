#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 *
 * [1329] 将矩阵按对角线排序
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
    {
        int m = mat.size(), n = mat[0].size();
        for (int j = n - 1; j >= 0; --j) {
            vector<int> tmp {};
            for (int i = 0; i < m && i + j < n; ++i) {
                tmp.push_back(mat[i][j + i]);
            }
            // for (auto& i : tmp) {
            //     printf("%d ", i);
            // }
            // printf("\n");
            sort(tmp.begin(), tmp.end());
            for (int i = 0; i < m && i + j < n; ++i) {
                mat[i][j + i] = tmp[i];
            }
        }
        for (int i = 1; i < m; ++i) {
            vector<int> tmp {};
            for (int j = 0; j < n && i + j < m; j++) {
                tmp.push_back(mat[i + j][j]);
            }
            // for (auto& i : tmp) {
            //     printf("%d ", i);
            // }
            // printf("\n");
            sort(tmp.begin(), tmp.end());
            for (int j = 0; j < n && i + j < m; ++j) {
                mat[i + j][j] = tmp[j];
            }
        }
        return mat;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<vector<int>> mat = { { 3, 3, 1, 1 }, { 2, 2, 1, 2 }, { 1, 1, 1, 2 } };
    sol.diagonalSort(mat);
    return 0;
}