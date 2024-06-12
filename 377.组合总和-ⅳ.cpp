#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        vector<unsigned long long> memo(target + 1);
        memo[0] = 1;
        int size = nums.size();
        for (int i = 1; i <= target; ++i) {
            for (auto& n : nums) {
                if (n <= i) {
                    memo[i] += memo[i - n];
                }
            }
        }

        return memo[target];
    }
};
// @lc code=end
