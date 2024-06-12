#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves)
    {
        int x { 0 }, y { 0 };
        for (auto& m : moves) {
            switch (m) {
            case 'U': {
                y++;
                break;
            }
            case 'D': {
                y--;
                break;
            }
            case 'L': {
                x--;
                break;
            }
            default: {
                x++;
                break;
            }
            }
        }
        return x == 0 && y == 0;
    }
};
// @lc code=end
