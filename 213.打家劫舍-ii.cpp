#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
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
        if (size == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> memo(size);
        memo[1] = nums[1];
        memo[2] = max(nums[1], nums[2]);
        for (int i = 3; i < size; ++i) {
            memo[i] = max(memo[i - 1], memo[i - 2] + nums[i]);
        }
        int result = memo[size - 1];
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size - 1; ++i) {
            memo[i] = max(memo[i - 1], memo[i - 2] + nums[i]);
        }
        result = max(result, memo[size - 2]);
        return result;
    }
};
// @lc code=end
