#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string>& words)
    {
        int n = words.size();
        vector<unsigned int> masks {};
        vector<int> lens;
        for (auto& w : words) {
            unsigned int mask = 0;
            for (auto c : w) {
                mask |= 1 << (c - 'a');
            }
            masks.push_back(mask);
            lens.push_back(w.size());
        }
        int res {};
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    res = max(lens[i] * lens[j], res);
                }
            }
        }
        return res;
    }
};
// @lc code=end
