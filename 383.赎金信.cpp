#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size())
            return false;
        int chars[26] = { 0 };
        for (auto& i : magazine) {
            chars[i - 'a']++;
        }
        for (auto& i : ransomNote) {
            chars[i - 'a']--;
            if (chars[i - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
