#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2317 lang=cpp
 *
 * [2317] 操作后的最大异或和
 */

// @lc code=start
class Solution {
public:
    int maximumXOR(vector<int>& nums)
    {
        int res {};
        for (auto& n : nums) {
            res |= n;
        }
        return res;
    }
};
// @lc code=end
