#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2033 lang=cpp
 *
 * [2033] 获取单值网格的最小操作数
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x)
    {
        int n = grid.size(), m = grid[0].size();
        vector<int> mem(n * m);
        int rem = grid[0][0] % x;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] % x != rem) {
                    return -1;
                }
                mem[i * m + j] = grid[i][j] / x;
            }
        }
        nth_element(mem.begin(), mem.begin() + n * m / 2, mem.end());
        int v = mem[n * m / 2];
        int res = 0;
        for (auto& vv : mem) {
            res += abs(vv - v);
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<vector<int>> grid { { 2, 4 }, { 6, 8 } };
    int x = 2;
    printf("%d\n", sol.minOperations(grid, x));
    grid = { { 529, 529, 989 }, { 989, 529, 345 }, { 989, 805, 69 } };
    x = 92;
    printf("%d\n", sol.minOperations(grid, x));
}