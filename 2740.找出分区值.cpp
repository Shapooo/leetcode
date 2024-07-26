#include <algorithm>
#include <limits>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2740 lang=cpp
 *
 * [2740] 找出分区值
 */

// @lc code=start
class Solution {
  public:
    int findValueOfPartition(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res{numeric_limits<int>::max()};
        for (int i = 1; i < n; ++i) {
            res = min(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};
// @lc code=end
