#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 */

// @lc code=start
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2)
    {
        int period_start = 0;
        int result = 0;
        int count = 0;
        int size = nums1.size();
        for (int i = 1; i < size; ++i) {
            if (nums1[i] <= nums1[i - 1] || nums2[i] <= nums2[i - 1]) {
                count += 1;
                swap(nums1[i], nums2[i]);
            } else if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                result += min(count, i - period_start - count);
                count = 0;
                period_start = i;
            }
        }
        result += min(count, size - period_start - count);
        return result;
    }
};
// @lc code=end
