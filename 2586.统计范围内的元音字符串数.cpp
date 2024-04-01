#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2586 lang=cpp
 *
 * [2586] 统计范围内的元音字符串数
 */

// @lc code=start
class Solution {
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int vowelStrings(vector<string>& words, int left, int right)
    {
        int res {};
        for (int i = left; i <= right; i++) {
            if (isVowel(words[i].front()) && isVowel(words[i].back())) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
