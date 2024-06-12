#include <algorithm>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int size1 = word1.size(), size2 = word2.size();
        if (size1 == 0) {
            return size2;
        }
        if (size2 == 0) {
            return size1;
        }
        int memo[size1][size2];
        memo[0][0] = word1[0] != word2[0];

        for (int i = 1; i < size2; ++i) {
            memo[0][i] = min((word1[0] != word2[i]) + i, memo[0][i - 1] + 1);
        }

        for (int i = 1; i < size1; ++i) {
            memo[i][0] = min((word1[i] != word2[0]) + i, memo[i - 1][0] + 1);
            for (int j = 1; j < size2; j++) {
                int tmp = (word1[i] != word2[j]) + memo[i - 1][j - 1];
                memo[i][j] = min({ memo[i - 1][j] + 1, memo[i][j - 1] + 1, tmp });
            }
        }
        return memo[size1 - 1][size2 - 1];
    }
};
// @lc code=end
