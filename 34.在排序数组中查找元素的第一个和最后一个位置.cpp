#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.empty()) {
            return { -1, -1 };
        }

        int lower = 0;
        int upper = static_cast<int>(nums.size()) - 1;

        while (lower < upper) {
            int index = lower + (upper - lower) / 2;
            if (nums[index] >= target) {
                upper = index;
            } else {
                lower = index + 1;
            }
        }

        if (nums[upper] != target) {
            return { -1, -1 };
        }

        int L = lower;
        upper = nums.size() - 1;
        while (lower < upper) {
            int index = lower + (upper - lower + 1) / 2;
            if (nums[index] <= target) {
                lower = index;
            } else {
                upper = index - 1;
            }
        }
        return { L, upper };
    }
};
// @lc code=end
