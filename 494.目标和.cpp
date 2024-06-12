#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        unordered_map<int, int>* memo = new unordered_map<int, int>();
        (*memo)[nums[0]] = 1;
        (*memo)[-nums[0]] += 1;
        for (int i = 1; i < nums.size(); ++i) {
            auto tmp = new unordered_map<int, int>();
            for (auto& kv : *memo) {
                (*tmp)[kv.first - nums[i]] += kv.second;
                (*tmp)[kv.first + nums[i]] += kv.second;
            }
            delete memo;
            memo = tmp;
        }
        int result = (*memo)[target];
        delete memo;
        return result;
    }
};
// @lc code=end
