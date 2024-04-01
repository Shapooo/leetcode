#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int xors {};
        for (auto& n : nums) {
            xors ^= n;
        }
        int lb = xors == 1 << 31 ? xors : xors & (-xors);
        int xora {}, xorb {};
        for (auto& n : nums) {
            if (n & lb) {
                xora ^= n;
            } else {
                xorb ^= n;
            }
        }
        return { xora, xorb };
    }
};
// @lc code=end
