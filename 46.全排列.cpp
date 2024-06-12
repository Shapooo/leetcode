#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        _helper(nums, 0);
        return _result;
    }
    void _helper(vector<int>& nums, int first)
    {
        int size = nums.size();
        if (first == size - 1) {
            _result.push_back(nums);
            return;
        }
        for (int i = first; i < size; ++i) {
            swap(nums[first], nums[i]);
            _helper(nums, first + 1);
            swap(nums[first], nums[i]);
        }
    }
    vector<vector<int>> _result {};
};
// @lc code=end
