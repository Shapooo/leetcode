#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int result = 0;
        int size = intervals.size();
        vector<pair<int, int>> _intervals(size);
        for (int i = 0; i < size; i++) {
            _intervals[i].first = intervals[i][1];
            _intervals[i].second = intervals[i][0];
        }
        sort(_intervals.begin(), _intervals.end());
        int edge = _intervals[0].first;
        for (int i = 1; i < size; ++i) {
            if (_intervals[i].second >= edge) {
                edge = _intervals[i].first;
            } else {
                ++result;
            }
        }

        return result;
    }
};
// @lc code=end
