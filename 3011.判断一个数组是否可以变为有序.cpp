#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=3011 lang=cpp
 *
 * [3011] 判断一个数组是否可以变为有序
 */

// @lc code=start
class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        int maxi = nums[0], bit_cnt = __builtin_popcount(nums[0]), prev_maxi = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] < prev_maxi)
            {
                return false;
            }
            int cnt = __builtin_popcount(nums[i]);
            if (cnt == bit_cnt)
            {
                maxi = max(maxi, nums[i]);
            }
            else
            {
                if (nums[i] < maxi)
                {
                    return false;
                }
                bit_cnt = cnt;
                prev_maxi = maxi;
                maxi = nums[i];
            }
        }
        return true;
    }
};
// @lc code=end
