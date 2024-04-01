#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1567 lang=cpp
 *
 * [1567] 乘积为正数的最长子数组长度
 */

// @lc code=start
class Solution {
public:
    int getMaxLen(vector<int>& nums)
    {
        int start { -1 }, neg_start { -1 };
        int n = nums.size();
        int res = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                start = i;
                neg_start = -1;
                cnt = 0;
            } else {
                if (nums[i] < 0) {
                    if (neg_start == -1) {
                        neg_start = i;
                    }
                    cnt++;
                }
                res = max(res, cnt % 2 ? i - neg_start : i - start);
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> nums { -4, 0, 0, -9, -10 };
    sol.getMaxLen(nums);
}