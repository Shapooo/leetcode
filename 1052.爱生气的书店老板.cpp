#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */

// @lc code=start
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
    {
        int len = customers.size();
        int acc = 0;
        for (int i = 0; i < len; ++i) {
            acc += grumpy[i] ? 0 : customers[i];
        }
        int wind = 0;
        for (int i = 0; i < minutes - 1; ++i) {
            acc += grumpy[i] * customers[i];
        }
        int res = 0;
        for (int i = minutes - 1; i < len; ++i) {
            acc += grumpy[i] * customers[i];
            res = max(res, acc);
            acc -= grumpy[i - minutes + 1] * customers[i - minutes + 1];
        }
        return res;
    }
};
// @lc code=end
