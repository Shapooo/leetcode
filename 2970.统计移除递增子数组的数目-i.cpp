#include <vector>
#include <cstdio>
using namespace std;
/*
 * @lc app=leetcode.cn id=2970 lang=cpp
 *
 * [2970] 统计移除递增子数组的数目 I
 */

// @lc code=start
class Solution
{
public:
    int incremovableSubarrayCount(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0;
        int i = 1;
        for (; i < n; ++i)
        {
            if (nums[i] <= nums[i - 1])
            {
                break;
            }
        }
        if (i == n)
        {
            return n * (n + 1) / 2;
        }
        res += i;
        int l = i;
        // printf("%d\n", res);
        i = n - 2;
        for (; i > 0; --i)
        {
            if (nums[i] >= nums[i + 1])
            {
                break;
            }
        }
        res += n - i;
        // printf("%d, %d, %d\n", res, l, i);
        int r = i;
        for (i = 0; i < l; ++i)
        {
            for (int j = n - 1; j > r; --j)
            {
                if (nums[i] < nums[j])
                {
                    res++;
                }
                else
                {
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol{};
    vector<int> nums{6, 5, 7, 8};
    sol.incremovableSubarrayCount(nums);
    return 0;
}