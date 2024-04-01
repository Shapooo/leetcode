#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2611 lang=cpp
 *
 * [2611] 老鼠和奶酪
 */

// @lc code=start
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k)
    {
        int len = reward1.size();
        auto cmp = [&](int lhs, int rhs) { return reward1[lhs] - reward2[lhs] < reward1[rhs] - reward2[rhs]; };
        vector<int> ctnr(len);
        int sum = 0;
        for (auto n : reward2) {
            sum += n;
        }
        for (int i = 0; i < len; ++i) {
            ctnr[i] = i;
        }
        priority_queue<int, vector<int>, decltype(cmp)> que(cmp, std::move(ctnr));
        for (int i = 0; i < k; ++i) {
            auto idx = que.top();
            sum += reward1[idx] - reward2[idx];
            que.pop();
        }
        return sum;
    }
};
// @lc code=end
