#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1958 lang=cpp
 *
 * [1958] 检查操作是否合法
 */

// @lc code=start
class Solution {
    bool valid(int r, int c)
    {
        return r >= 0 && r < 8 && c >= 0 && c < 8;
    }

public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color)
    {
        vector<pair<int, int>> dir { { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, 1 }, { 0, -1 }, { -1, 1 }, { -1, 0 }, { -1, -1 } };
        char mid_color;
        if (color == 'B') {
            mid_color = 'W';
        } else {
            mid_color = 'B';
        }
        for (auto& delta : dir) {
            bool valid_mid = false;
            for (int i = 1; i < 8; ++i) {
                if (valid(rMove + delta.first * i, cMove + delta.second * i)) {
                    char cur_color = board[rMove + delta.first * i][cMove + delta.second * i];
                    if (cur_color == '.') {
                        break;
                    }
                    if (!valid_mid) {
                        if (cur_color == mid_color) {
                            valid_mid = true;
                        } else {
                            break;
                        }
                    } else if (cur_color == color) {
                        return true;
                    }
                } else {
                    break;
                }
            }
        }
        return false;
    }
};
// @lc code=end
