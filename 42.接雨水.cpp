#include <stack>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height)
    {
        int size = height.size();
        int width { 0 };
        int bar_acc { 0 };
        int result { 0 };
        int idx = 0;
        stack<pair<int, int>> stk {};
        while (idx < size - 1 && height[idx + 1] >= height[idx]) {
            ++idx;
        }
        stk.push({ height[idx], idx });
        for (; idx < size; ++idx) {
            int pre = stk.top().first;
            while (!stk.empty() && stk.top().first <= height[idx]) {
                auto tmp = stk.top();
                stk.pop();
                result += (tmp.first - pre) * (idx - tmp.second - 1);
                pre = tmp.first;
            }
            if (!stk.empty()) {
                result += (height[idx] - pre) * (idx - stk.top().second - 1);
            }
            stk.push({ height[idx], idx });
        }
        return result;
    }
};
// @lc code=end
