#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=849 lang=cpp
 *
 * [849] 到最近的人的最大距离
 */

// @lc code=start
class Solution {
public:
    int maxDistToClosest(vector<int>& seats)
    {
        int idx = 0;
        int n = seats.size();
        for (; !seats[idx]; ++idx) { }
        int res = idx;
        int left = idx;
        for (; idx < n; ++idx) {
            if (seats[idx]) {
                res = max(res, (idx - left) / 2);
                left = idx;
            }
        }
        res = max(res, n - left - 1);
        return res;
    }
};
// @lc code=end
