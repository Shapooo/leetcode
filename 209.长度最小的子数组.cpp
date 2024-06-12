#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int l = 0, r = 0, len = 0, sum = 0;
        auto size = nums.size();
        while (r <= size) {
            if (target > sum) {
                if (r == size) {
                    break;
                }
                sum += nums[r++];
            } else {
                int cur_len = r - l;
                if (!len) {
                    len = cur_len;
                } else if (cur_len < len) {
                    len = cur_len;
                }
                sum -= nums[l];
                l++;
            }
        }
        return len;
    }
};
// @lc code=end
