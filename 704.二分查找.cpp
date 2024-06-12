#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target)
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
        return -1;
    }
};
// @lc code=end
