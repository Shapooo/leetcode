#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        int n = nums.size();
        if (goal) {
            int pre_sum[30'002] {};
            for (int i = 1; i <= n; ++i) {
                pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
            }
            int map[30'001] {};
            for (int i = 0; i <= n; ++i) {
                map[pre_sum[i]]++;
            }
            int res = 0;
            for (int i = 0; i <= n - goal; ++i) {
                res += map[i] * map[i + goal];
            }
            return res;
        } else {
            int cur = 0;
            int res {};
            for (int i = 0; i < n; ++i) {
                if (nums[i]) {
                    cur = 0;
                } else {
                    cur += 1;
                    res += cur;
                }
            }
            return res;
        }
    }
};
// @lc code=end