#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=2103 lang=cpp
 *
 * [2103] 环和杆
 */

// @lc code=start
class Solution {
public:
    int countPoints(string rings)
    {
        int pole[10][3] {};
        int n = rings.size() / 2;
        for (int i = 0; i < n; ++i) {
            int r = rings[i * 2 + 1] - '0';
            int c = rings[i * 2] == 'R' ? 0 : rings[i * 2] == 'G' ? 1
                                                                  : 2;
            pole[r][c] = 1;
        }
        int res {};
        for (int i = 0; i < 10; ++i) {
            if (pole[i][0] && pole[i][1] && pole[i][2]) {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
