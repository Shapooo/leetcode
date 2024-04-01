#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2100 lang=cpp
 *
 * [2100] 适合打劫银行的日子
 */

// @lc code=start
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time)
    {
        int n = security.size();
        if (n < 2 * time) {
            return {};
        }
        vector<int> res {};
        int pre_ok_days { 1 }, post_ok_days { 1 };
        for (int i = 1; i <= time; ++i) {
            if (security[i] > security[i - 1]) {
                pre_ok_days = 0;
            } else {
                pre_ok_days++;
            }
        }
        for (int i = time; i <= time * 2; ++i) {
            if (security[i] < security[i - 1]) {
                post_ok_days = 0;
            } else {
                post_ok_days++;
            }
        }
        for (int i = time; i < n - time; ++i) {
            if (security[i] > security[i]) {
                pre_ok_days = 0;
            } else {
                pre_ok_days++;
            }
            if (security[i + time] < security[i + time + 1]) {
            }
        }
        return res;
    }
};
// @lc code=end
