#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

// @lc code=start
class Solution {
    int abs(int a) { return a < 0 ? -a : a; }
    int dist_sq(int x1, int y1, int x2, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
    {
        vector<pair<int, int>> cords {};
        vector<int> dist {};
        vector<int> indx {};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; ++j) {
                cords.emplace_back(i, j);
                dist.emplace_back(dist_sq(rCenter, cCenter, i, j));
                indx.emplace_back(i * cols + j);
            }
        }
        sort(indx.begin(), indx.end(), [&dist](int lhs, int rhs) {
            return dist[lhs] < dist[rhs];
        });
        vector<vector<int>> res {};
        for (auto i : indx) {
            res.emplace_back(vector<int> { cords[i].first, cords[i].second });
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    int rows = 3, cols = 5, rCenter = 2, cCenter = 3;
    for (auto& p : sol.allCellsDistOrder(rows, cols, rCenter, cCenter)) {
    }
}