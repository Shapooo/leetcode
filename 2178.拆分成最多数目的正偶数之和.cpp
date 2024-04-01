#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2178 lang=cpp
 *
 * [2178] 拆分成最多数目的正偶数之和
 */

// @lc code=start
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        if (finalSum % 2) {
            return {};
        }
        vector<long long> res {};
        long long cur = 2;
        while (cur <= finalSum) {
            res.push_back(cur);
            finalSum -= cur;
            cur += 2;
        }
        res.back() += finalSum;
        return res;
    }
};
// @lc code=end
