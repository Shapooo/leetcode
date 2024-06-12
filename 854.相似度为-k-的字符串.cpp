#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=854 lang=cpp
 *
 * [854] 相似度为 K 的字符串
 */

// @lc code=start
class Solution {
public:
    int kSimilarity(string s1, string s2)
    {
        int size = s1.size();
        if (size < 2) {
            return 0;
        }
        int result { 0 };
        for (int i = 0; i < size; ++i) {
            if (s1[i] != s2[i]) {
                int j = i + 1;
                for (; j < size; ++j) {
                    if (s1[j] == s2[i] && s1[j] != s2[j]) {
                        break;
                    }
                }
                result++;
                s1[j] = s1[i];
            }
        }
        return result;
    }
};
// @lc code=end
