#include <bitset>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */

// @lc code=start
class Solution {
    int m, n;
    int traverse(int colToSel, int start, vector<vector<int>>& matrix, bitset<32>& path)
    {
        if (n < start + colToSel) {
            return 0;
        }
        if (colToSel == 0) {
            int res = 0;
            for (int i = 0; i < m; ++i) {
                bool flag = true;
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == 1 && !path[j]) {
                        flag = false;
                        break;
                    }
                }
                res += flag;
            }
            return res;
        }
        path[start] = 1;
        int res = traverse(colToSel - 1, start + 1, matrix, path);
        path[start] = 0;
        res = max(res, traverse(colToSel, start + 1, matrix, path));
        return res;
    }

public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect)
    {
        m = matrix.size(), n = matrix[0].size();
        bitset<32> path {};
        return traverse(numSelect, 0, matrix, path);
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<vector<int>> matrix { { 0 } };
    int numSelect = 1;
    sol.maximumRows(matrix, numSelect);
}