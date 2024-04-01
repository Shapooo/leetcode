#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1041 lang=cpp
 *
 * [1041] 困于环中的机器人
 */

// @lc code=start
class Solution {
public:
    bool isRobotBounded(string instructions)
    {
        int pace[4][2] = { { 0, 1 }, { -1, 0 }, { 0, -1 }, { 1, 0 } };
        int direction = 0;
        int x {}, y {};
        for (auto&& c : instructions) {
            switch (c) {
            case 'G':
                x += pace[direction][0];
                y += pace[direction][1];
                break;
            case 'L':
                direction = (direction + 1) % 4;
                break;
            case 'R':
                direction = (direction + 3) % 4;
                break;
            default:
                break;
            }
        }
        if ((x || y) && !direction) {
            return false;
        } else {
            return true;
        }
    }
};
// @lc code=end
