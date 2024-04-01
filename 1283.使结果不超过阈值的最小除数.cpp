#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1283 lang=cpp
 *
 * [1283] 使结果不超过阈值的最小除数
 */

// @lc code=start
class Solution {
    bool fulfil(vector<int>& nums, int threshold, int k)
    {
        long long sum = 0;
        for (auto n : nums) {
            sum += (n + k - 1) / k;
        }
        return sum <= threshold;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        long long sum = 0;
        int ma = 0;
        for (auto n : nums) {
            sum += n;
            ma = max(ma, n);
        }
        int l = (sum + threshold - 1) / threshold;
        if (fulfil(nums, threshold, l)) {
            return l;
        }
        int r = ma;
        printf("%d\n", l);
        while (l < r - 1) {
            if (fulfil(nums, threshold, l + (r - l) / 2)) {
                r = l + (r - l) / 2;
            } else {
                l = l + (r - l) / 2;
            }
        }
        return r;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> nums { 21212, 10101, 12121 };
    int threshold = 1000000;
    sol.smallestDivisor(nums, threshold);
}