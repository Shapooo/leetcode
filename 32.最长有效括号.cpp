#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s)
    {
        int size = s.size();
        if (!size) {
            return 0;
        }
        // vector<vector<int>> memo(size, vector<int>(size));
        vector<int> memo(size);
        int result = 0;
        for (int i = 0; i < size; ++i) {
            if (s[i] == '(') {
                memo[i] = 1;
            } else {
                memo[i] = -10e5;
            }
        }

        for (int i = 1; i < size; ++i) {
            for (int j = size - 1; j >= i; --j) {
                memo[j] = memo[j - 1] + (s[j] == '(' ? 1 : -1);
                if (memo[j] == 0) {
                    result = i + 1;
                } else if (memo[j] < 0) {
                    memo[j] = -10e5;
                }
            }
        }
        return result;
    }
};
// @lc code=end
