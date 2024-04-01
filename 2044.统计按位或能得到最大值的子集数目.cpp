#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2044 lang=cpp
 *
 * [2044] 统计按位或能得到最大值的子集数目
 */

// @lc code=start
class Solution {
    int or_max {};
    int rec(vector<int>& nums, int idx, int cur_or)
    {
        if (idx == nums.size()) {
            return cur_or == or_max;
        }
        return rec(nums, idx + 1, cur_or) + rec(nums, idx + 1, cur_or | nums[idx]);
    }

public:
    int countMaxOrSubsets(vector<int>& nums)
    {
        for (auto&& i : nums) {
            or_max |= i;
        }
        return rec(nums, 0, 0);
    }
};
// @lc code=end
