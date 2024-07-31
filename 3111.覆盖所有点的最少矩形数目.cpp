#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=3111 lang=cpp
 *
 * [3111] 覆盖所有点的最少矩形数目
 */

// @lc code=start
class Solution {
  public:
    int minRectanglesToCoverPoints(vector<vector<int>> &points, int w) {
        sort(points.begin(), points.end());
        int res = 1;
        int left_edge = points[0][0];
        for (auto const &p : points) {
            if (p[0] - left_edge > w) {
                left_edge = p[0];
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution sol{};
    vector<vector<int>> points{{2, 1}, {1, 0}, {1, 4}, {1, 8}, {3, 5}, {4, 6}};
    int w = 1;
    sol.minRectanglesToCoverPoints(points, w);
}