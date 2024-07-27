#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=3106 lang=cpp
 *
 * [3106] 满足距离约束且字典序最小的字符串
 */

// @lc code=start
class Solution {
    int char_dist(char a, char b) {
        if (a > b) {
            return min(a - b, b + 26 - a);
        } else {
            return min(b - a, a + 26 - b);
        }
    }

  public:
    string getSmallestString(string s, int k) {
        string res{};
        for (auto const &c : s) {
            auto dist = char_dist('a', c);
            if (dist > k) {
                res.push_back(c - k);
                k = 0;
            } else {
                res.push_back('a');
                k -= dist;
            }
        }

        return res;
    }
};
// @lc code=end
