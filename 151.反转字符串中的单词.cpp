#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s)
    {
        string result {};
        int size = s.size();
        result.reserve(s.size() + 1);
        int startIndex = s.size() - 1;
        while (startIndex >= 0) {
            int count = 0;
            while (startIndex >= 0 && s[startIndex] != ' ') {
                count++;
                startIndex--;
            }
            if (count) {
                result.append(s, startIndex + 1, count);
                result.push_back(' ');
            }
            while (startIndex >= 0 && s[startIndex] == ' ') {
                startIndex--;
            }
        }
        result.pop_back();

        return result;
    }
};
// @lc code=end
