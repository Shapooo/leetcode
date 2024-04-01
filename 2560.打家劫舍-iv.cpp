#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2560 lang=cpp
 *
 * [2560] 打家劫舍 IV
 */

// @lc code=start
class Solution {
    int n;
    int cnt(vector<int>& nums, int ability)
    {
        int res {};
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= ability) {
                res++, i++;
            }
        }
        return res;
    }

public:
    int minCapability(vector<int>& nums, int k)
    {
        n = nums.size();
        auto ma = max_element(nums.begin(), nums.end()), mi = min_element(nums.begin(), nums.end());
        int l = *mi, r = *ma;
        while (l <= r) {
            int mid = (l + r) / 2;
            int tmp = cnt(nums, mid);
            if (tmp < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
// @lc code=end
