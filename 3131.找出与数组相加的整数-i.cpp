#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=3131 lang=cpp
 *
 * [3131] 找出与数组相加的整数 I
 */

// @lc code=start
class Solution {
  public:
    int addedInteger(vector<int> &nums1, vector<int> &nums2) {
        int mini1 = 1001, mini2 = 1001;
        for (auto const &n : nums1) {
            mini1 = min(mini1, n);
        }
        for (auto const &n : nums2) {
            mini2 = min(mini2, n);
        }
        return mini2 - mini1;
    }
};
// @lc code=end
