#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
    void _helper(int n, int row, vector<string>& path,
        vector<vector<string>>& result)
    {
        if (row == n) {
            result.push_back(path);
        }
        for (int seq = 0; seq < n; seq++) {
            bool succ = true;
            for (int j = 0; j < row; j++) {
                if (path[j][seq] == 'Q') {
                    succ = false;
                    break;
                }
                if (seq - row + j >= 0 && path[j][seq - row + j] == 'Q') {
                    succ = false;
                    break;
                }
                if (seq + row - j < n && path[j][seq + row - j] == 'Q') {
                    succ = false;
                    break;
                }
            }
            if (succ) {
                path[row][seq] = 'Q';
                _helper(n, row + 1, path, result);
                path[row][seq] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> _result {};
        vector<string> _path(n, string(n, '.'));
        _helper(n, 0, _path, _result);
        return _result;
    }
};
// @lc code=end
