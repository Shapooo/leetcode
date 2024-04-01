#include <cmath>
#include <cstdio>
using namespace std;
/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
    double a[32] {};
    int i = 1;
    double rec(int n)
    {
        int e = log2(n);
        int r = pow(2., e);
        if (n == r) {
            return a[e];
        } else {
            return a[e] * rec(n - r);
        }
    }

public:
    double _pow(double x, int n)
    {
        int v = 2;
        a[0] = x;

        while (v <= n) {
            a[i] = a[i - 1] * a[i - 1];
            if (i == 30) {
                break;
            }
            i++, v *= 2;
        }
        return rec(n);
    }
    double myPow(double x, int n)
    {
        if (x == 1.) {
            return 1.;
        }
        if (n == 0) {
            return 1;
        } else if (n > 0) {
            return pow(x, n);
        } else {
            if (n == 1 << 31) {
                return 1.0 / (pow(x, (~0u) >> 1) * x);
            } else {
                return 1.0 / pow(x, -n);
            }
        }
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    double x = 8.95371;
    int n = -1;
    printf("%lf\n", sol.myPow(x, n));
    x = 1.10000;
    n = -2147483648;
    printf("%lf\n", sol.myPow(x, n));
    x = 2.;
    printf("%lf\n", sol.myPow(x, n));
    printf("%d", (~0u) >> 1);
}