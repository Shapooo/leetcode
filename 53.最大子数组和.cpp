#include <climits>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int result = INT_MIN;
        int sum = 0;
        for (auto& i : nums) {
            sum = max(0, sum) + i;
            result = max(result, sum);
        }
        return result;
    }
};
// @lc code=end
