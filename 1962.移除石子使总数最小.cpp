#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1962 lang=cpp
 *
 * [1962] 移除石子使总数最小
 */

// @lc code=start
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k)
    {
        int sum = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> q(piles.begin(), piles.end());
        for (int i = 0; i < k; ++i) {
            int t = q.top();
            q.pop();
            q.push(t - t / 2);
            sum -= t / 2;
        }
        return sum;
    }
};
// @lc code=end
