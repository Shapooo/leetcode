#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        _helper(candidates, 0, target, 0);
        return _ans;
    }
    void _helper(vector<int>& candidates, int start, int target, int sum)
    {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            _ans.push_back(_path);
            return;
        }
        int size = candidates.size();
        for (int i = start; i < size; ++i) {
            _path.push_back(candidates[i]);
            _helper(candidates, i, target, sum + candidates[i]);
            _path.pop_back();
        }
    }
    vector<vector<int>> _ans {};
    vector<int> _path {};
};
// @lc code=end
