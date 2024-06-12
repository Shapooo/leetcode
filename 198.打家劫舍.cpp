#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        vector<int> memo(nums.size());
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i) {
            memo[i] = max(memo[i - 1], memo[i - 2] + nums[i]);
        }
        return memo[size - 1];
    }
};
// @lc code=end
