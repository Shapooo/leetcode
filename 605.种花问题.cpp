#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int cnt {}, bc { 1 };
        for (auto& f : flowerbed) {
            if (f) {
                cnt += (bc - 1) / 2;
                bc = 0;
            } else {
                bc++;
            }
        }
        cnt += bc / 2;
        return cnt >= n;
    }
};
// @lc code=end
