#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        _helper(1, n + 1, k);
        return _result;
    }
    void _helper(int start, int n, int k)
    {
        if (n - start < k - _path.size()) {
            return;
        } else if (_path.size() == k) {
            _result.push_back(_path);
        }
        for (int i = start; i < n; ++i) {
            _path.push_back(i);
            _helper(i + 1, n, k);
            _path.pop_back();
        }
    }
    vector<vector<int>> _result {};
    vector<int> _path {};
};
// @lc code=end
