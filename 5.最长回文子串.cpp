#include <bitset>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s)
    {
        int max = 1;
        int left = 0;
        int size = s.size();
        bitset<1000> memo[1000] {};
        memo[0][0] = 1;
        for (int i = 1; i < size; ++i) {
            memo[i][i] = 1;
            if (s[i - 1] == s[i]) {
                memo[i - 1][i] = 1;
                left = i - 1;
                max = 2;
            }
        }

        for (int len = 3; len <= size; ++len) {
            for (int i = 0; i <= size - len; ++i) {
                if (s[i] == s[i + len - 1]) {
                    if (memo[i + 1][i + len - 2]) {
                        memo[i][i + len - 1] = 1;
                        if (len > max) {
                            left = i;
                            max = len;
                        }
                    }
                }
            }
        }

        return string(s, left, max);
    }
};
// @lc code=end
