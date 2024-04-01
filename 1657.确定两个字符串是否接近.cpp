#include <string>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=1657 lang=cpp
 *
 * [1657] 确定两个字符串是否接近
 */

// @lc code=start
class Solution {
public:
    bool closeStrings(string word1, string word2)
    {
        unordered_map<char, int> m1, m2;
        unordered_map<int, int> m3, m4;
        for (auto c : word1) {
            m1[c]++;
        }
        for (auto c : word2) {
            m2[c]++;
        }
        for (auto& p : m1) {
            m3[p.second]++;
        }
        for (auto& p : m2) {
            m4[p.second]++;
        }
        if (m1.size() != m2.size()) {
            return false;
        }
        for (auto& p : m1) {
            if (m2[p.first] == 0) {
                return false;
            }
        }
        for (auto& p : m3) {
            if (m4[p.first] != p.second) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
