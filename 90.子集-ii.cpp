#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        _helper(nums, 0);
        return _ans;
    }
    void _helper(vector<int>& nums, int start)
    {
        int size = nums.size();

        _ans.push_back(_path);
        if (start == size) {
            return;
        }

        for (int i = start; i < size; ++i) {
            auto tmp = nums[i];
            if (i != start && tmp == nums[i - 1]) {
                continue;
            }
            _path.push_back(tmp);
            _helper(nums, i + 1);
            _path.pop_back();
        }
    }
    vector<vector<int>> _ans {};
    vector<int> _path {};
};
// @lc code=end
