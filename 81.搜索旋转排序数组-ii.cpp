#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool rec1(vector<int>& nums, int l, int r, int target)
    {
        while (l <= r) {
            if (nums[(l + r) / 2] < target) {
                l = (l + r) / 2 + 1;
            } else if (nums[(l + r) / 2] > target) {
                r = (l + r) / 2 - 1;
            } else {
                return true;
            }
        }
        return false;
    }

    bool rec3(vector<int>& nums, int l, int r, int target)
    {
        int m = (l + r) / 2;
        if (nums[m] > target) {
            return rec1(nums, l, m, target);
        } else if (nums[m] == target) {
            return true;
        } else if (nums[m] >= nums[l]) {
            return rec3(nums, m, r, target);
        } else {
            return rec3(nums, l, m, target);
        }
    }
    bool rec4(vector<int>& nums, int l, int r, int target)
    {
        int m = (l + r) / 2;
        if (nums[m] < target) {
            return rec1(nums, m, r, target);
        } else if (nums[m] == target) {
            return true;
        } else if (nums[m] <= nums[r]) {
            return rec4(nums, l, m, target);
        } else {
            return rec3(nums, m, r, target);
        }
    }

    // bool rec2(vector<int>& nums, int l, int r, int target)
    // {
    //     if (l >= r) {
    //         return target == nums[l];
    //     }
    //     int m = (l + r) / 2;
    //     if (nums[m] == nums[l]) {
    //         if (nums[m + 1] == nums[l]) {
    //             return rec2(nums, l, m, target) || rec2(nums, m + 1, r, target);
    //         } else if (nums[m + 1] > nums[l]) {
    //             if (target)
    //         }
    //     }
    // }
    bool search(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        // int m = (l + r) / 2;
        // if (nums[l] > nums[r]) {
        //     if (target == nums[l] || target == nums[r]) {
        //         return true;
        //     } else if (target > nums[l]) {
        //         return rec3(nums, l, r, target);
        //     } else if (target < nums[r]) {
        //         return rec4(nums, l, r, target);
        //     } else {
        //         return false;
        //     }
        // } else if (nums[l] < nums[r]) {
        //     if (target == nums[l] || target == nums[r]) {
        //         return true;
        //     } else if (target < nums[l] || target > nums[r]) {
        //         return false;
        //     } else {
        //         return rec1(nums, l, r, target);
        //     }
        // } else {
            // return rec2(nums, l, r, target);
            for (int i = 0; i <= r; ++i) {
                if (nums[i] == target) {
                    return true;
                }
            }
            return false;
        // }
    }
};
// @lc code=end
