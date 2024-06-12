#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> que(stones.begin(), stones.end());
        while (que.size() > 1) {
            int a = que.top();
            que.pop();
            int b = que.top();
            que.pop();
            a = a - b;
            if (a) {
                que.push(a);
            }
        }
        return que.empty() ? 0 : que.top();
    }
};
// @lc code=end
