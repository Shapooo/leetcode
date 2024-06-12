#include <algorithm>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 */

// @lc code=start
class Solution {
public:
    int uniqueLetterString(string s)
    {
        int size = s.size();
        int result = 0;
        for (int c = 'A'; c <= 'Z'; ++c) {
            int right = 0, cur = 0, left = -1;
            while (cur < size && s[cur] != c) {
                cur++;
            }
            while (cur < size) {
                right = cur + 1;
                while (right < size && s[right] != c) {
                    right++;
                }
                for (int s = 1; s < right - left; ++s) {
                    result += min({ s, cur - left, right - cur, right - left - s });
                }
                left = cur;
                cur = right;
            }
        }
        return result;
    }
};
// @lc code=end
