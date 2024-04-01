#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2563 lang=cpp
 *
 * [2563] 统计公平数对的数目
 */

// @lc code=start
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long res {};
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] * 2 > upper) {
                break;
            }
            if (nums[i] + nums.back() < lower) {
                continue;
            }
            int l = lower - nums[i];
            int u = upper - nums[i];
            auto it_l = lower_bound(nums.begin() + i + 1, nums.end(), l) - nums.begin();
            auto it_u = upper_bound(nums.begin() + i + 1, nums.end(), u) - nums.begin();
            res += it_u - it_l;
        }
        return res;
    }
};
// @lc code=end
