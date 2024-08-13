#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=3151 lang=cpp
 *
 * [3151] 特殊数组 I
 */

// @lc code=start
class Solution {
  public:
    bool isArraySpecial(vector<int> &nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
