#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> memo(size, 1);
        int result = 1;
        memo[0] = 1;
        for (int i = 1; i < size; ++i) {
            for (int j = i; j >= 0; --j) {
                if (nums[i] > nums[j]) {
                    memo[i] = max(memo[j] + 1, memo[i]);
                }
            }
            result = max(result, memo[i]);
        }
        return result;
    }
};
// @lc code=end
