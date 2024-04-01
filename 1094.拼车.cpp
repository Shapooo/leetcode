#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        int geton[1001] {}, getoff[1001] {};
        for (auto& trip : trips) {
            geton[trip[1]] += trip[0];
            getoff[trip[2]] += trip[0];
        }
        int cur {};
        for (int i = 0; i < 1001; ++i) {
            cur += geton[i];
            cur -= getoff[i];
            if (cur > capacity) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int>> trips = { { 9, 3, 4 }, { 9, 1, 7 }, { 4, 2, 4 }, { 7, 4, 5 } };
    int capacity = 23;
    s.carPooling(trips, capacity);
    return 0;
}