#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1578 lang=cpp
 *
 * [1578] 使绳子变成彩色的最短时间
 */

// @lc code=start
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int n = neededTime.size();
        int idx = 0;
        int res {};
        while (idx < n) {
            idx++;
            if (idx < n && colors[idx] == colors[idx - 1]) {
                int max_time = neededTime[idx - 1];
                int total_time = max_time;
                while (idx < n && colors[idx] == colors[idx - 1]) {
                    total_time += neededTime[idx];
                    max_time = max(max_time, neededTime[idx]);
                    idx++;
                }
                cout << idx << total_time - max_time << endl;
                res += total_time - max_time;
            }
        }

        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution sol;
    string colors = "abaac";
    vector<int> neededTime = { 1, 2, 3, 4, 5 };
    cout << sol.minCost(colors, neededTime) << endl;
    colors = "aabaa", neededTime = { 1, 2, 3, 4, 1 };
    cout << sol.minCost(colors, neededTime) << endl;
    return 0;
}
