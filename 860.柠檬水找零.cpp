#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
    {
        int five = 0;
        int ten = 0;
        for (auto& i : bills) {
            if (i == 5) {
                five++;
            } else if (i == 10) {
                if (five < 1) {
                    return false;
                } else {
                    --five;
                    ++ten;
                }
            } else {
                if (ten && five) {
                    --ten;
                    --five;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
