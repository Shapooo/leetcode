#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2140 lang=cpp
 *
 * [2140] 解决智力问题
 */

// @lc code=start
class Solution {
    long long dp[100'001] {};

public:
    long long mostPoints(vector<vector<int>>& questions)
    {
        int n = questions.size();
        long long res {}, ma {};
        for (int i = 0; i < n; ++i) {
            ma = max(ma, dp[i]);
            int ntjump = i + questions[i][1] + 1;
            if (ntjump >= n) {
                res = max(res, ma + questions[i][0]);
            } else {
                dp[ntjump] = max(dp[ntjump], ma + questions[i][0]);
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<vector<int>> questions { { 3, 2 }, { 4, 3 }, { 4, 4 }, { 2, 5 } };
    return 0;
}