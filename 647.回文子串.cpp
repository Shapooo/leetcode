#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s)
    {
        int size = s.size();
        int result = size;
        for (int i = 0; i < size - 1; ++i) {
            int left = i - 1, right = i + 1;
            while (left >= 0 && right < size && s[left] == s[right]) {
                left--;
                right++;
                result++;
            }
            left = i, right = i + 1;
            while (left >= 0 && right < size && s[left] == s[right]) {
                left--;
                right++;
                result++;
            }
        }
        return result;
    }
};
// @lc code=end
