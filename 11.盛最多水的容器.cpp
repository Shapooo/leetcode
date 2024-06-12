#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int result = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            if (height[left] > height[right]) {
                result = max(result, height[right] * (right - left));
                --right;
            } else {
                result = max(result, height[left] * (right - left));
                ++left;
            }
        }
        return result;
    }
};
// @lc code=end
