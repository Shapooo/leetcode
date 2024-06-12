#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int size = intervals.size();
        vector<pair<int, int>> _intervals(size);
        for (int i = 0; i < size; ++i) {
            _intervals[i].first = intervals[i][0];
            _intervals[i].second = intervals[i][1];
        }
        sort(_intervals.begin(), _intervals.end());
        vector<vector<int>> result {};
        int left = _intervals[0].first, right = _intervals[0].second;
        for (int i = 1; i < size; ++i) {
            if (_intervals[i].first > right) {
                result.push_back({ left, right });
                left = _intervals[i].first;
                right = _intervals[i].second;
            } else {
                right = max(right, _intervals[i].second);
            }
        }
        result.push_back({ left, right });
        return result;
    }
};
// @lc code=end
