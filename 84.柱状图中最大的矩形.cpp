#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        vector<pair<int, int>> stk {};
        int result { 0 };
        int size = heights.size();
        heights.push_back(0);

        for (int i = 0; i < size; ++i) {
            while (!stk.empty() && heights[i] <= stk.back().first) {
                stk.pop_back();
            }
            int area {};
            if (stk.empty()) {
                area = heights[i] * (i + 1);
            } else {
                int pre = -1;
                area = (i - stk.back().second) * heights[i];
                for (auto& j : stk) {
                    auto tmp = j.first * (i - pre);
                    pre = j.second;
                    area = area > tmp ? area : tmp;
                }
            }
            result = area > result ? area : result;
            stk.push_back({ heights[i], i });
        }

        return result;
    }
};
// @lc code=end
