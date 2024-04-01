#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1209 lang=cpp
 *
 * [1209] 删除字符串中的所有相邻重复项 II
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        string res {};
        vector<int> stk {};
        for (auto c : s) {
            if (res.empty()) {
                res.push_back(c);
                stk.push_back(1);
            } else {
                if (res.back() == c) {
                    if (stk.back() + 1 == k) {
                        for (int i = 0; i < k - 1; ++i) {
                            res.pop_back();
                        }
                        stk.pop_back();
                    } else {
                        res.push_back(c);
                        stk.back()++;
                    }
                } else {
                    res.push_back(c);
                    stk.push_back(1);
                }
            }
        }
        return res;
    }
};
// @lc code=end
