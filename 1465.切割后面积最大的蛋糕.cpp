#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1465 lang=cpp
 *
 * [1465] 切割后面积最大的蛋糕
 */

// @lc code=start
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
    {
        horizontalCuts.push_back(h);
        horizontalCuts.push_back(0);
        verticalCuts.push_back(w);
        verticalCuts.push_back(0);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int v_max {}, h_max {};
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            h_max = max(h_max, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i) {
            v_max = max(v_max, verticalCuts[i] - verticalCuts[i - 1]);
        }
        return (long long)h_max * v_max % 1000000007;
    }
};
// @lc code=end
