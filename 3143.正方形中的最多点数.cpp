#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=3143 lang=cpp
 *
 * [3143] 正方形中的最多点数
 */

// @lc code=start
class Solution {
    int max_pos(vector<int> &point) {
        return max(abs(point[0]), abs(point[1]));
    }

  public:
    int maxPointsInsideSquare(vector<vector<int>> &points, string s) {
        int n = points.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](size_t lhs, size_t rhs) {
            int l = max_pos(points[lhs]);
            int r = max_pos(points[rhs]);
            return l < r;
        });
        int set[26]{};
        int res{};
        for (; res < n; ++res) {
            if (set[s[idx[res]] - 'a']) {
                break;
            } else {
                set[s[idx[res]] - 'a'] = 1;
            }
        }

        if (res == n) {
            return res;
        }
        int b = max_pos(points[idx[res]]);
        res--;
        while (res >= 0 && max_pos(points[idx[res]]) == b) {
            res--;
        }
        return res + 1;
    }
};
// @lc code=end

int main() {
    Solution sol{};
    vector<vector<int>> points = {{2, 2}, {-1, -2}, {-4, 4}, {-3, 1}, {3, -3}};
    string s = "abdca";
    points = {{1, 1}, {-2, -2}, {-2, 2}}, s = "abb";
    points = {{1, 1}, {-1, -1}, {2, -2}}, s = "ccd";
    sol.maxPointsInsideSquare(points, s);
    return {};
}