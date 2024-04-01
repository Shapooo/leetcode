#include <cmath>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=2558 lang=cpp
 *
 * [2558] 从数量最多的堆取走礼物
 */

// @lc code=start
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k)
    {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        long long total {};
        for (auto& n : gifts) {
            total += n;
        }
        for (int i = 0; i < k; ++i) {
            int n = pq.top();
            pq.pop();
            int rem = sqrt(n);
            total -= n - rem;
            pq.push(rem);
        }
        return total;
    }
};
// @lc code=end
