#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int target = 0;
        for (auto& i : nums) {
            target += i;
        }
        if (target % 2) {
            return false;
        }
        target /= 2;
        vector<vector<int>> memo(nums.size(), vector<int>(target + 1));

        for (int i = nums[0]; i <= target; ++i) {
            memo[0][i] = nums[0];
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= target; ++j) {
                if (j < nums[i]) {
                    memo[i][j] = memo[i - 1][j];
                } else {
                    memo[i][j] = max(memo[i - 1][j - nums[i]] + nums[i], memo[i - 1][j]);
                }
            }
        }

        return memo[nums.size() - 1][target] == target;
    }
};
// @lc code=end
