#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1608 lang=cpp
 *
 * [1608] 特殊数组的特征值
 */

// @lc code=start
class Solution {
public:
    int specialArray(vector<int>& nums)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int result { 0 };
        for (int i = size - 1; i >= 0 && nums[i] >= result; --i, ++result)
            ;
        if (nums[size - result] >= result) {
            return result;
        } else {
            return -1;
        }
    }
};
// @lc code=end
