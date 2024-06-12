#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
    vector<vector<int>> _result {};
    void _helper(vector<int>& nums, vector<int>& used)
    {
        int size = nums.size();
        if (size == 1) {
            used.push_back(nums[0]);
            _result.push_back(used);
            used.pop_back();
            return;
        }
        for (int i = 0; i < size; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            auto tmp { nums };
            used.push_back(nums[i]);
            tmp.erase(tmp.begin() + i);
            _helper(tmp, used);
            used.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> used {};
        _helper(nums, used);
        return _result;
    }
};
// @lc code=end
