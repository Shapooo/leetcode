#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        _helper(nums, 0);
        return _ans;
    }
    void _helper(vector<int>& nums, int start)
    {
        int size = nums.size();

        _ans.push_back(_path);
        for (int i = start; i < size; ++i) {
            _path.push_back(nums[i]);
            _helper(nums, i + 1);
            _path.pop_back();
        }
    }
    vector<vector<int>> _ans {};
    vector<int> _path {};
};
// @lc code=end
