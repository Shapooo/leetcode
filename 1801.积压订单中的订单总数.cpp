#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1801 lang=cpp
 *
 * [1801] 积压订单中的订单总数
 */

// @lc code=start
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders)
    {
        vector<vector<int>> buy_que {};
        auto cmp = [](auto& lhs, auto& rhs) {
            return lhs[0] > rhs[0];
        };
        vector<vector<int>> sell_que {};
        for (auto& o : orders) {
            if (o[2]) {
                while (o[1] && !buy_que.empty() && o[0] <= buy_que[0][0]) {
                    auto& b = buy_que[0];
                    if (b[1] > o[1]) {
                        b[1] -= o[1];
                        o[1] = 0;
                    } else {
                        o[1] -= b[1];
                        pop_heap(buy_que.begin(), buy_que.end());
                        buy_que.pop_back();
                    }
                }
                if (o[1]) {
                    sell_que.push_back(std::move(o));
                    push_heap(sell_que.begin(), sell_que.end(), cmp);
                }
            } else {
                while (o[1] && !sell_que.empty() && o[0] >= sell_que[0][0]) {
                    auto& s = sell_que[0];
                    if (s[1] > o[1]) {
                        s[1] -= o[1];
                        o[1] = 0;
                    } else {
                        o[1] -= s[1];
                        pop_heap(sell_que.begin(), sell_que.end(), cmp);
                        sell_que.pop_back();
                    }
                }
                if (o[1]) {
                    buy_que.push_back(std::move(o));
                    push_heap(buy_que.begin(), buy_que.end());
                }
            }
        }
        long long res {}, MOD = 1000'000'007;
        for (auto& o : buy_que) {
            res = (res + o[1]) % MOD;
        }
        for (auto& o : sell_que) {
            res = (res + o[1]) % MOD;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<vector<int>> orders { { 26, 7, 0 }, { 16, 1, 1 }, { 14, 20, 0 }, { 23, 15, 1 }, { 24, 26, 0 }, { 19, 4, 1 }, { 1, 1, 0 } };
    sol.getNumberOfBacklogOrders(orders);
}