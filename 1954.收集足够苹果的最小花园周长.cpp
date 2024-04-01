#include <algorithm>
#include <cstdio>
using namespace std;
/*
 * @lc app=leetcode.cn id=1954 lang=cpp
 *
 * [1954] 收集足够苹果的最小花园周长
 */

// @lc code=start
class Solution {
    long long calc(long long n)
    {
        return n * (n + 1) * (2 * n + 1) * 2;
    }

public:
    long long minimumPerimeter(long long neededApples)
    {
        int l = 1, r = 144225;
        while (l < r) {
            int mid = (l + r) / 2;
            long long cnt = calc(mid);
            if (cnt == neededApples) {
                return mid * 8;
            } else if (cnt > neededApples) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l * 8;
    }
};
// @lc code=end

int main()
{
    long long target = 1000'000'000'000'000;
    long long n = 1;
    long long count = 0;
    while (true) {
        long long sum = n * (n + 1) * (2 * n + 1) / 6;
        if (sum <= target) {
            printf("%lld %lld\n", n, sum);
            count++;
            ++n;
        } else {
            break;
        }
    }
    printf("%lld\n", count);
}