#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=2525 lang=cpp
 *
 * [2525] 根据规则将箱子分类
 */

// @lc code=start
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        long long volume = (long long)length * width * height;
        bool bulky = volume >= 1000'000'000 || length >= 10'000 || width >= 10'000 || height >= 10'000;
        bool heavy = mass >= 100;
        if (heavy && bulky) {
            return "Both";
        } else if (bulky) {
            return "Bulky";
        } else if (heavy) {
            return "Heavy";
        } else {
            return "Neither";
        }
    }
};
// @lc code=end
