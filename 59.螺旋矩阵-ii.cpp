#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    enum { RIGHT = 0,
        DOWN,
        LEFT,
        UP } direct
        = RIGHT;
    vector<vector<int>> generateMatrix(int n)
    {
        int count = 1;

        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int i = 0; i < (n + 1) / 2; ++i) {
            _oneCircle(result, i, i, n - i * 2 - 1, count);
        }

        return result;
    }
    inline void _oneCircle(vector<vector<int>>& vec, int start_x, int start_y,
        int len, int& index)
    {
        if (len == 0) {
            vec[start_y][start_x] = index++;
            return;
        }
        for (int i = 0; i < len; i++) {
            vec[start_y][start_x + i] = index++;
        }
        for (int i = 0; i < len; i++) {
            vec[start_y + i][start_x + len] = index++;
        }
        for (int i = 0; i < len; i++) {
            vec[start_y + len][start_x + len - i] = index++;
        }
        for (int i = 0; i < len; i++) {
            vec[start_y + len - i][start_x] = index++;
        }
    }
};
// @lc code=end
