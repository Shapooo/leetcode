#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2085 lang=cpp
 *
 * [2085] 统计出现过一次的公共字符串
 */

// @lc code=start
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2)
    {
        unordered_map<string, int> mp1, mp2;
        for (auto& word : words1) {
            mp1[word]++;
        }
        for (auto& word : words2) {
            mp2[word]++;
        }
        int res = 0;
        for (auto& [word, cnt] : mp1) {
            if (cnt == 1 && mp2[word] == 1) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
