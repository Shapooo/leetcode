#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=2211 lang=cpp
 *
 * [2211] 统计道路上的碰撞次数
 */

// @lc code=start
class Solution {
public:
    int countCollisions(string directions)
    {
        bool collided = false;
        int to_coll = 0;
        bool stoped = false;
        int res = 0;
        for (auto c : directions) {
            if (!collided) {
                if (c == 'S') {
                    collided = true;
                } else if (c == 'R') {
                    to_coll++;
                    collided = true;
                }
            } else {
                if (c == 'S') {
                    res += to_coll;
                    to_coll = 0;
                } else if (c == 'L') {
                    res += to_coll + 1;
                    to_coll = 0;
                } else {
                    to_coll++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
