#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
    constexpr static int N = 9;

public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (auto& v : board) {
            for (int i = 0; i < N; ++i) {
                if (v[i] != '.') {
                    for (int j = i + 1; j < N; ++j) {
                        if (v[j] == v[i]) {
                            return false;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[j][i] != '.') {
                    for (int k = j + 1; k < N; ++k) {
                        if (board[k][i] == board[j][i]) {
                            return false;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int base_x = (i / 3) * 3;
                int base_y = (i % 3) * 3;
                int x = base_x + (j / 3);
                int y = base_y + (j % 3);
                if (board[x][y] != '.') {
                    for (int k = j + 1; k < N; ++k) {
                        if (board[x][y] == board[base_x + k / 3][base_y + k % 3]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
