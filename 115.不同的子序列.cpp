#include <cstring>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t)
    {
        int s_size = s.size(), t_size = t.size();
        if (s_size < t_size) {
            return 0;
        }
        unsigned int memo[t_size][s_size];
        memset(memo, 0, sizeof(int) * s_size * t_size);

        memo[0][0] = t[0] == s[0];
        for (int i = 1; i < s_size; ++i) {
            memo[0][i] = memo[0][i - 1] + (t[0] == s[i]);
        }

        for (int i = 1; i < t_size; ++i) {
            for (int j = i; j < s_size; ++j) {
                int tmp = memo[i][j - 1];
                tmp += (t[i] == s[j]) ? memo[i - 1][j - 1] : 0;
                memo[i][j] = tmp;
            }
        }
        return memo[t_size - 1][s_size - 1];
    }
};
// @lc code=end
