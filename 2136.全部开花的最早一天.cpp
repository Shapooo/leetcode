#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2136 lang=cpp
 *
 * [2136] 全部开花的最早一天
 */

// @lc code=start
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime)
    {
        int n = plantTime.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int lhs, int rhs) { return growTime[lhs] > growTime[rhs]; });
        int res {}, time {};
        for (auto& i : idx) {
            time += plantTime[i];
            res = max(res, time + growTime[i]);
        }
        return res;
    }
};
// @lc code=end
