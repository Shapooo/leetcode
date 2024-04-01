#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int r = nums.size() - 1;
        int l = 0;
        if (nums[l] < nums[r]) {
            return nums[l];
        }
        while (l < r - 1) {
            if (nums[(r + l) / 2] > nums[l]) {
                l = (r + l) / 2;
            } else {
                r = (r + l) / 2;
            }
        }
        return nums[r];
    }
};
// @lc code=end
