#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1829 lang=cpp
 *
 * [1829] 每个查询的最大异或值
 */

// @lc code=start
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit)
    {
        int n = nums.size();
        int a = (1 << maximumBit) - 1;
        int acc = 0;
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            acc ^= nums[i];
            res[n - i - 1] = acc ^ a;
        }
        return res;
    }
};
// @lc code=end
