#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2171 lang=cpp
 *
 * [2171] 拿出最少数目的魔法豆
 */

// @lc code=start
class Solution {
public:
    long long minimumRemoval(vector<int>& beans)
    {
        sort(beans.begin(), beans.end());
        long long sum = accumulate(beans.begin(), beans.end(), 0LL);
        int n = beans.size();
        long long res = sum;
        for (int i = 0; i < n; ++i) {
            res = min(res, sum - (long long)(n - i) * beans[i]);
        }
        return res;
    }
};
// @lc code=end
