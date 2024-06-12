#include <bitset>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        bitset<300> memo {};
        int size = s.size();
        memo[0] = 1;
        for (int i = 1; i <= size; ++i) {
            for (auto& w : wordDict) {
                int size = w.size();
                if (size <= i && memo[i - size] && !w.compare(0, size, s, i - size, size)) {
                    memo[i] = true;
                }
            }
        }
        return memo[size];
    }
};
// @lc code=end
