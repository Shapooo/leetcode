#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s)
    {
        string result {};
        for (auto c : s) {
            if (result.empty() || result.back() != c) {
                result.push_back(c);
            } else {
                result.pop_back();
            }
        }
        return result;
    }
};
// @lc code=end
