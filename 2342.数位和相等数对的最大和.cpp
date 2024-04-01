#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 *
 * [2342] 数位和相等数对的最大和
 */

// @lc code=start
class Solution {
    int bit_sum(int n)
    {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums)
    {
        int cache[100][2] {};
        int res { -1 };
        for (auto& n : nums) {
            int sum = bit_sum(n);
            if (n > cache[sum][0] && n > cache[sum][1]) {
                if (cache[sum][0] > cache[sum][1]) {
                    cache[sum][1] = n;
                } else {
                    cache[sum][0] = n;
                }
            } else if (n > cache[sum][0]) {
                cache[sum][0] = n;
            } else if (n > cache[sum][1]) {
                cache[sum][1] = n;
            }
            if (cache[sum][0] && cache[sum][1]) {
                res = max(res, cache[sum][0] + cache[sum][1]);
            }
        }
        return res;
    }
};
// @lc code=end
