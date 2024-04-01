#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        int n = nums.size();
        if (!n) {
            return {};
        }
        int left = nums[0], last = nums[0];
        vector<string> res {};
        for (int i = 1; i < n; ++i) {
            if (nums[i] == last + 1) {
                last = nums[i];
            } else {
                if (last == left) {
                    res.push_back(to_string(last));
                } else {
                    res.push_back(to_string(left) + "->" + to_string(last));
                }
                last = nums[i];
                left = nums[i];
            }
        }
        if (last == left) {
            res.push_back(to_string(last));
        } else {
            res.push_back(to_string(left) + "->" + to_string(last));
        }
        return res;
    }
};
// @lc code=end
