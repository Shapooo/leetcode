/*
 * @lc app=leetcode.cn id=1401 lang=cpp
 *
 * [1401] 圆和矩形是否有重叠
 */

// @lc code=start
class Solution {
    long long squ(int a)
    {
        return (long long)a * a;
    }
    bool in_circle(int xCenter, int yCenter, int radius, int x, int y)
    {
        int sq_radius = radius * radius;
        return squ(xCenter - x) + squ(yCenter - y) <= sq_radius;
    }

public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        if (xCenter >= x1 && xCenter <= x2 && yCenter <= y2 && yCenter >= y1) {
            return true;
        }
        if (xCenter >= x1 && xCenter <= x2 && (yCenter < y1 && y1 - yCenter <= radius || yCenter > y2 && yCenter - y2 <= radius)) {
            return true;
        }
        if (yCenter >= y1 && yCenter <= y2 && (xCenter < x1 && x1 - xCenter <= radius || xCenter > x2 && xCenter - x2 <= radius)) {
            return true;
        }
        return in_circle(xCenter, yCenter, radius, x1, y1) || in_circle(xCenter, yCenter, radius, x1, y2) || in_circle(xCenter, yCenter, radius, x2, y1) || in_circle(xCenter, yCenter, radius, x2, y2);
    }
};
// @lc code=end
