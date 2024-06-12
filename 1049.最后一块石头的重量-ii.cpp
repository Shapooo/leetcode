#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones)
    {
        int sum = 0;
        for (auto& i : stones) {
            sum += i;
        }
        int target = sum / 2;
        vector<int> memo(target + 1);
        for (auto& i : stones) {
            for (int j = target; j >= i; --j) {
                memo[j] = max(memo[j], memo[j - i] + i);
            }
        }
        return sum - memo[target] * 2;
    }
};
// @lc code=end
