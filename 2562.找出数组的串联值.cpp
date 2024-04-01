#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2562 lang=cpp
 *
 * [2562] 找出数组的串联值
 */

// @lc code=start
class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums)
    {
        int l = 0, r = nums.size() - 1;
        long long res = 0;
        while (l < r) {
            int lv = nums[l], rv = nums[r];
            res += rv;
            while (rv) {
                rv /= 10;
                lv *= 10;
            }
            res += lv;
            l++, r--;
        }
        if (l == r) {
            res += nums[l];
        }
        return res;
    }
};
// @lc code=end
