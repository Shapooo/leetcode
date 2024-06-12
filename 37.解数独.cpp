#include <bitset>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
    constexpr static int N = 9;
    bool backtrace(vector<vector<char>>& board, int i, int j)
    {
        if (i == N) {
            return true;
        }
        if (board[i][j] != '.') {
            if (j == N - 1) {
                return backtrace(board, i + 1, 0);
            } else {
                return backtrace(board, i, j + 1);
            }
        }
        bitset<N> map {};
        for (int k = 0; k < N; ++k) {
            if (k != j && board[i][k] != '.') {
                map[board[i][k] - '1'] = 1;
            }
            if (k != i && board[k][j] != '.') {
                map[board[k][j] - '1'] = 1;
            }
            int x = i / 3 * 3 + k / 3;
            int y = j / 3 * 3 + k % 3;
            if ((x != i || y != j) && board[x][y] != '.') {
                map[board[x][y] - '1'] = 1;
            }
        }
        for (int k = 0; k < N; ++k) {
            if (map[k] == 0) {
                board[i][j] = k + '1';
                bool result {};
                if (j == N - 1) {
                    result = backtrace(board, i + 1, 0);
                } else {
                    result = backtrace(board, i, j + 1);
                }
                if (result) {
                    return result;
                }
            }
        }
        board[i][j] = '.';
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) { backtrace(board, 0, 0); }
};
// @lc code=end
