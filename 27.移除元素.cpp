#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        auto l = nums.begin(), r = l;
        while (r < nums.end()) {
            if (*r == val) {
                r++;
                continue;
            } else {
                *l++ = *r++;
            }
        }
        return l - nums.begin();
    }
};
// @lc code=end
