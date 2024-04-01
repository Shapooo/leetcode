#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
 */

// @lc code=start
class Solution {
    int mem[10'001] {};

public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        int acc = 0;
        int res = 0;
        mem[0] = 1;
        for (auto& n : nums) {
            acc = (((acc + n) % k) + k) % k;
            res += mem[acc];
            mem[acc]++;
        }

        return res;
    }
};
// @lc code=end
