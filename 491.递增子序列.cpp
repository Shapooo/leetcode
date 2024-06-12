#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        int size = nums.size();
        if (size < 2)
            return _ans;
        for (int i = 0; i < size; ++i) {
            _path.push_back(nums[i]);
            _helper(nums, i + 1);
            _path.pop_back();
        }
        return _ans;
    }
    void _helper(vector<int>& nums, int start)
    {
        if (_path.size() >= 2) {
            _ans.push_back(_path);
        }
        int size = nums.size();
        if (size == start) {
            return;
        }
        // bool dupPushed = false;
        for (int i = start; i < size; ++i) {
            auto tmp = nums[i];
            if (i != start && nums[i - 1] == tmp) {
                continue;
            }
            if (tmp >= nums[start - 1]) {
                _path.push_back(tmp);
                _helper(nums, i + 1);
                _path.pop_back();
            }
        }
    }
    vector<vector<int>> _ans {};
    vector<int> _path {};
};
// @lc code=end
