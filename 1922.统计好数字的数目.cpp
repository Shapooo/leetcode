#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1922 lang=cpp
 *
 * [1922] 统计好数字的数目
 */

// @lc code=start
class Solution {
public:
    int countGoodNumbers(long long n)
    {
        long long MOD = 1000'000'007;
        long long mem[51] {};
        mem[0] = 5;
        mem[1] = 20;
        int idx = 2;
        long long v = 4;
        while (v <= n) {
            mem[idx] = (mem[idx - 1] * mem[idx - 1]) % MOD;
            idx++;
            v *= 2;
        }
        int res = 1;
        v /= 2;
        idx--;
        while (n) {
            if (n >= v) {
                n -= v;
                res = res * mem[idx] % MOD;
            }
            // printf("%lld %d %lld\n", n, idx, v);
            idx--;
            v /= 2;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    long long n = 1;
    printf("%d\n", sol.countGoodNumbers(n));
}