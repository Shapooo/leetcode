#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n)
    {
        int result = 0;
        vector<int> memo(n + 1);
        memo[0] = 1;
        memo[1] = 1;
        for (int i = 1; i < n; ++i) {
            int sum = 0;
            for (int j = 0; j <= (i - 1) / 2; j++) {
                sum += 2 * memo[j] * memo[i - j];
            }
            if (i % 2 == 0) {
                sum += memo[i / 2] * memo[i / 2];
            }
            memo[i + 1] = sum;
        }

        return memo[n];
    }
};
// @lc code=end
