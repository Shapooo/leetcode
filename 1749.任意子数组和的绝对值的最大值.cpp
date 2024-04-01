#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1749 lang=cpp
 *
 * [1749] 任意子数组和的绝对值的最大值
 */

// @lc code=start
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums)
    {
        int ma {}, mi {};
        int p_acc {}, n_acc {};
        for (auto& i : nums) {
            p_acc += i;
            n_acc += i;
            if (p_acc < 0) {
                p_acc = 0;
            }
            if (n_acc > 0) {
                n_acc = 0;
            }
            ma = max(p_acc, ma);
            mi = min(n_acc, mi);
        }
        return max(abs(mi), ma);
    }
};
// @lc code=end
