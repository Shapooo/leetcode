#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        unsigned long index = nums.size() / 2;
        unsigned long lower = 0;
        unsigned long upper = nums.size();

        while (lower < upper) {
            if (nums[index] == target) {
                return index;
            } else if (nums[index] > target) {
                upper = index;
            } else {
                lower = index + 1;
            }
            index = lower + (upper - lower) / 2;
        }

        return index;
    }
};
// @lc code=end
