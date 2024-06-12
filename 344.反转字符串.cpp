#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s)
    {
        auto size = s.size();
        for (int i = 0; i < size / 2; i++) {
            auto tmp = s[i];
            s[i] = s[size - i - 1];
            s[size - i - 1] = tmp;
        }
    }
};
// @lc code=end
