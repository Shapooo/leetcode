#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1455 lang=cpp
 *
 * [1455] 检查单词是否为句中其他单词的前缀
 */

// @lc code=start
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        int idx = 0;
        int n = sentence.size();
        int res { 1 };
        while (idx < n) {
            while (sentence[idx] == ' ') {
                idx++;
            }
            int i = 0;
            while (i < searchWord.size() && idx + i < n && sentence[idx + i] == searchWord[i]) {
                i++;
            }
            if (i == searchWord.size()) {
                return res;
            }
            idx = idx + i;
            while (idx < n && sentence[idx] != ' ') {
                idx++;
            }
            res++;
        }
        return -1;
    }
};
// @lc code=end