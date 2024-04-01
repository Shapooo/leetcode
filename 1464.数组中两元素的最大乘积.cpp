#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        sort(nums.rbegin(), nums.rend());
        return (nums[0] - 1) * (nums[1] - 1);
    }
};
// @lc code=end
