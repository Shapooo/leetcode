#include <bitset>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        bitset<128> set;
        int size = s.size();
        int result = 0;
        for (int right = 0, left = 0; right < size; ++right) {
            if (!set[s[right]]) {
                set[s[right]] = 1;
            } else {
                while (left < right && s[left] != s[right]) {
                    set[s[left]] = 0;
                    left++;
                }
                if (s[left] == s[right]) {
                    left++;
                }
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
// @lc code=end
