#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        bitset<16 * 10000 + 1> memo {};
        int sum = 0;
        for (auto& i : nums) {
            memo[0] = 1;
            memo >> i;
            sum += i;
        }

        if (sum % k) {
            return false;
        }
        int period = sum / k;
        for (int i = 1; i <= k; ++i) {
            if (memo[period * i] == 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
