#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1738 lang=cpp
 *
 * [1738] 找出第 K 大的异或坐标值
 */

// @lc code=start
class Solution {

    int mem[1000'000];

public:
    int kthLargestValue(vector<vector<int>>& matrix, int k)
    {
        priority_queue<int, vector<int>, greater<int>> que {};

        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int tv;
                if (i == 0 && j == 0) {
                    tv = matrix[0][0];
                } else if (i == 0) {
                    tv = matrix[0][j - 1] ^ matrix[0][j];
                    matrix[0][j] = tv;
                } else if (j == 0) {
                    tv = matrix[i - 1][0] ^ matrix[i][0];
                    matrix[i][0] = tv;
                } else {
                    tv = matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1] ^ matrix[i][j];
                    matrix[i][j] = tv;
                }
                mem[i * n + j] = tv;
            }
        }
        nth_element(mem, mem + k - 1, mem + n * m, greater<>());
        return mem[k - 1];
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<vector<int>> matrix { { 9 } };
    int k = 1;
    sol.kthLargestValue(matrix, k);
}