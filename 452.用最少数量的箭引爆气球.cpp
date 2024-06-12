#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        int result = 1;
        int size = points.size();
        vector<pair<int, int>> _points(size);
        for (int i = 0; i < size; ++i) {
            _points[i].first = points[i][1];
            _points[i].second = points[i][0];
        }
        sort(_points.begin(), _points.end());
        int arrow = _points[0].first;
        for (int i = 1; i < size; ++i) {
            if (arrow < _points[i].second) {
                ++result;
                arrow = _points[i].first;
            }
        }

        return result;
    }
};
// @lc code=end
