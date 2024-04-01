#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=885 lang=cpp
 *
 * [885] 螺旋矩阵 III
 */

// @lc code=start
class Solution {
    int _rows {};
    int _cols {};
    bool check(int x, int y)
    {
        return x >= 0 && x < _rows && y >= 0 && y < _cols;
    }

public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        int delta[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        _rows = rows, _cols = cols;
        int total = rows * cols;
        int cnt { 1 };
        vector<vector<int>> res { { rStart, cStart } };
        int len = 1;
        int dir = 0;
        while (cnt < total) {
            for (int i = 0; i < len && cnt < total; ++i) {
                rStart += delta[dir][0];
                cStart += delta[dir][1];
                if (check(rStart, cStart)) {
                    res.emplace_back(vector<int> { rStart, cStart });
                    cnt++;
                }
            }
            dir = (dir + 1) % 4;
            for (int i = 0; i < len && cnt < total; ++i) {
                rStart += delta[dir][0];
                cStart += delta[dir][1];
                if (check(rStart, cStart)) {
                    res.emplace_back(vector<int> { rStart, cStart });
                    cnt++;
                }
            }
            dir = (dir + 1) % 4;
            len++;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    int rows = 1, cols = 4, rStart = 0, cStart = 0;
    sol.spiralMatrixIII(rows, cols, rStart, cStart);
}