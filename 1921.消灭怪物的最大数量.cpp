#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1921 lang=cpp
 *
 * [1921] 消灭怪物的最大数量
 */

// @lc code=start
class Solution {
    int m[100'001] {};

public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed)
    {
        int n = dist.size();
        int latest = 0;
        for (int i = 0; i < n; ++i) {
            int t = (dist[i] - 1) / speed[i];
            m[t]++;
            latest = max(latest, t);
        }
        int res = 0;
        for (int i = 0; i <= latest; ++i) {
            if (res + m[i] > i + 1) {
                return i + 1;
            } else {
                res += m[i];
            }
        }
        return res;
    }
};
// @lc code=end
