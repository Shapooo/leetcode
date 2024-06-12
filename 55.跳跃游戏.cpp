#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int farest = 0;
        int size = nums.size();
        int i = 0;
        for (int i = 0; i < size && i <= farest && farest < size - 1; ++i) {
            farest = max(nums[i] + i, farest);
        }
        return farest >= size - 1;
    }
};
// @lc code=end
