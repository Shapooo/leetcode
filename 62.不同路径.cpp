#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        unsigned long long result = 1;
        int tmp = min(m, n) - 1;
        m += n - 2;
        n = tmp;
        for (int i = 1; i <= n; ++i) {
            result *= m--;
            result /= i;
        }
        return result;
    }
};
// @lc code=end
