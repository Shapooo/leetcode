#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        if (obstacleGrid[0][0]) {
            return 0;
        }
        int flag = 0;
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        for (auto& i : obstacleGrid[0]) {
            if (flag) {
                i = 0;
            } else if (i == 1) {
                flag = 1;
                i = 0;
            } else {
                i = 1;
            }
        }
        flag = 0;
        for (int i = 1; i < height; ++i) {
            if (flag) {
                obstacleGrid[i][0] = 0;
            } else if (obstacleGrid[i][0] == 1) {
                flag = 1;
                obstacleGrid[i][0] = 0;
            } else {
                obstacleGrid[i][0] = 1;
            }
        }
        for (int i = 1; i < height; ++i) {
            for (int j = 1; j < width; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                } else {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                }
            }
        }
        return obstacleGrid[height - 1][width - 1];
    }
};
// @lc code=end
