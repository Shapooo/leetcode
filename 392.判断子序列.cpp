#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int size = s.size();
        if (!size) {
            return true;
        }
        int index = 0;
        for (auto& c : t) {
            if (c == s[index]) {
                index++;
            }
            if (index == size) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
