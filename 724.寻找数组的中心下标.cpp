#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size(), acc{};
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; ++i)
        {
            prefixSum[i] = acc;
            acc += nums[i];
        }
        prefixSum[n] = acc;
        for (int i = 0; i < n; ++i)
        {
            if (prefixSum[i] == acc - prefixSum[i + 1])
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
