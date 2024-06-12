#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s)
    {
        int size = s.size();
        int memo[size][size];
        memo[0][0] = 1;
        for (int i = 1; i < size; ++i) {
            memo[i][i] = 1;
            memo[i - 1][i] = (s[i - 1] == s[i]) + 1;
        }

        for (int n = 2; n < size; ++n) {
            for (int i = 0; i < size - n; ++i) {
                if (s[i] == s[i + n]) {
                    memo[i][i + n] = memo[i + 1][i + n - 1] + 2;
                } else {
                    memo[i][i + n] = max(memo[i + 1][i + n], memo[i][i + n - 1]);
                }
            }
        }

        return memo[0][size - 1];
    }
};
// @lc code=end
