#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1509 lang=cpp
 *
 * [1509] 三次操作后最大值与最小值的最小差
 */

// @lc code=start
class Solution {
public:
    int minDifference(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 5) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int res = 2'000'000'001;
        for (int i = 0; i < 4; ++i) {
            int l = nums[i], r = nums[n - 4 + i];
            res = min(res, r - l);
        }
        return res;
    }
};
// @lc code=end
