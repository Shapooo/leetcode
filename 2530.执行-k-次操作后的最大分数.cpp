#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=2530 lang=cpp
 *
 * [2530] 执行 K 次操作后的最大分数
 */

// @lc code=start
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k)
    {
        long long res {};
        priority_queue<int, vector<int>> que(std::less<int>(), std::move(nums));
        for (int i = 0; i < k; ++i) {
            int tmp = que.top();
            que.pop();
            res += tmp;
            que.push((tmp + 2) / 3);
        }
        return res;
    }
};
// @lc code=end
