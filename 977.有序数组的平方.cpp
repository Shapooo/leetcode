#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        if (nums.empty())
            return {};
        vector<int> result {};
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= 0) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        l--;
        while (l >= 0 && r < nums.size()) {
            int a = nums[l] * nums[l];
            int b = nums[r] * nums[r];
            if (a < b) {
                result.push_back(a);
                l--;
            } else {
                result.push_back(b);
                r++;
            }
        }
        while (l >= 0) {
            result.push_back(nums[l] * nums[l]);
            l--;
        }
        while (r <= nums.size() - 1) {
            result.push_back(nums[r] * nums[r]);
            r++;
        }
        return result;
    }
};
// @lc code=end
