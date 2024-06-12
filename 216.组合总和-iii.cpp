#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        if (n < k)
            return _ans;
        _helper(1, k, n);
        return _ans;
    }
    void _helper(int start, int k, int n)
    {
        if (_sum > n) {
            return;
        }
        if (_path.size() == k) {
            if (_sum == n) {
                _ans.push_back(_path);
            }
            return;
        }
        if (n < (k - _path.size()) * start + _sum) {
            return;
        }
        for (int i = start; i < 10; ++i) {
            _path.push_back(i);
            _sum += i;
            _helper(i + 1, k, n);
            _sum -= i;
            _path.pop_back();
        }
    }
    vector<vector<int>> _ans {};
    vector<int> _path {};
    int _sum { 0 };
};
// @lc code=end
