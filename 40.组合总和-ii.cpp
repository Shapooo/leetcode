#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
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
        int i = start;
        for (int i = start; i < size; ++i) {
            auto tmp = candidates[i];
            if (tmp > target) {
                break;
            }
            if (i != start && tmp == candidates[i - 1]) {
                continue;
            }
            _path.push_back(tmp);
            _helper(candidates, i + 1, target, sum + tmp);
            _path.pop_back();
        }
    }
    vector<vector<int>> _ans {};
    vector<int> _path {};
};
// @lc code=end
