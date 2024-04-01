#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2588 lang=cpp
 *
 * [2588] 统计美丽子数组数目
 */

// @lc code=start
class Solution {
    int counteract(int a, int b)
    {
        return (a | b) ^ (a & b);
    }
    long long arith_sum(int a)
    {
        long long res = a;
        res *= res - 1;
        return res / 2;
    }

public:
    long long beautifulSubarrays(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int> mm { { 0, 1 } };
        int acc = 0;
        for (auto& n : nums) {
            acc = counteract(acc, n);
            mm[acc]++;
        }
        long long res {};
        for (auto& p : mm) {
            res += arith_sum(p.second);
        }
        return res;
    }
};
// @lc code=end
