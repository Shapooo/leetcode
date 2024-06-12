#include <cstring>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int size1 = text1.size(), size2 = text2.size();
        int memo[size2];
        memset(memo, 0, sizeof(int) * size2);

        for (auto& c : text1) {
            int prev = memo[0];
            memo[0] = text2[0] == c || memo[0];

            for (int i = 1; i < size2; ++i) {
                int tmp = prev;
                prev = memo[i];
                memo[i] = text2[i] == c ? tmp + 1 : max(memo[i - 1], memo[i]);
            }
        }

        return memo[size2 - 1];
    }
};
// @lc code=end
