#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1276 lang=cpp
 *
 * [1276] 不浪费原料的汉堡制作方案
 */

// @lc code=start
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
    {
        if (tomatoSlices > 4 * cheeseSlices || tomatoSlices < 2 * cheeseSlices || tomatoSlices % 2 != 0) {
            return {};
        }
        tomatoSlices /= 2;
        return { tomatoSlices - cheeseSlices, 2 * cheeseSlices - tomatoSlices };
    }
};
// @lc code=end
