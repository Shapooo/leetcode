#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2008 lang=cpp
 *
 * [2008] 出租车的最大盈利
 */

// @lc code=start
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides)
    {
        sort(rides.begin(), rides.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<long long> dp(n + 1, 0);
        int cur_ride = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            while (cur_ride < rides.size() && rides[cur_ride][1] < i) {
                ++cur_ride;
            }
            while (cur_ride < rides.size() && rides[cur_ride][1] == i) {
                dp[i] = max(dp[i], dp[rides[cur_ride][0]] + rides[cur_ride][1] - rides[cur_ride][0] + rides[cur_ride][2]);
                ++cur_ride;
            }
        }
        // for (auto ride : rides) {
        // printf("%d %d %d %d\n", ride[0], ride[1], ride[2], ride[1] - ride[0] + ride[2]);
        // }
        // for (int i = 1; i <= n; ++i) {
        // printf("%lld ", dp[i]);
        // }
        return dp[n];
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<int>> rides = { { 4, 5, 8 }, { 3, 6, 6 }, { 1, 3, 3 }, { 2, 5, 9 }, { 4, 9, 5 }, { 8, 9, 10 }, { 3, 8, 5 }, { 3, 5, 2 }, { 3, 7, 10 }, { 9, 10, 6 } };
    sol.maxTaxiEarnings(10, rides);
    return 0;
}