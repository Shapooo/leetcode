#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int result = 1;
        int begin = 0;
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            if (nums[i] <= nums[i - 1]) {
                begin = i;
            } else {
                result = max(result, i - begin + 1);
            }
        }
        return result;
    }
};
// @lc code=end
