#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int mi = nums[0], ma = mi, total = 0;
        int nma = INT32_MIN;
        int pacc = 0, nacc = 0;
        auto len = nums.size();
        for (int i = 0; i < len; ++i) {
            total += nums[i];
            pacc += nums[i];
            nacc += nums[i];
            mi = min(mi, nacc);
            ma = max(ma, pacc);
            // cout << mi << ' ' << ma << endl;
            if (nums[i] < 0) {
                nma = max(nma, nums[i]);
            }
            if (pacc < 0) {
                pacc = 0;
            }
            if (nacc > 0) {
                nacc = 0;
            }
        }
        if (total == mi && nma != INT32_MIN) {
            mi -= nma;
        }

        return max(total - mi, ma);
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> nums { -3, -2, -3 };
    cout << sol.maxSubarraySumCircular(nums) << endl;
    nums = { -5, 4, -6 };
    cout << sol.maxSubarraySumCircular(nums) << endl;
}
