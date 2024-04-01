#include <cstdio>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 *
 * [1155] 掷骰子的N种方法
 */

// @lc code=start
using ll = long long;
class Solution {
    long long matrix[31][1001] {};

public:
    int numRollsToTarget(int n, int k, int target)
    {
        ll MOD = 1'000'000'007;
        if (n > target || n * k < target) {
            return 0;
        }
        for (int i = 1; i <= k; ++i) {
            matrix[1][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = i; j <= i * k && j < target; ++j) {
                if (matrix[i][j]) {
                    for (int a = 1; a <= k && j + a <= target; ++a) {
                        matrix[i + 1][j + a] = (matrix[i + 1][j + a] + matrix[i][j]) % MOD;
                    }
                }
            }
        }
        printf("%lld\n", matrix[n][target]);
        cout << matrix[n][target] << endl;
        return matrix[n][target];
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    int n = 1, k = 6, target = 3;
    printf("%d\n", sol.numRollsToTarget(n, k, target));
    n = 2, k = 6, target = 7;
    printf("%d\n", sol.numRollsToTarget(n, k, target));
    n = 30, k = 30, target = 500;
    printf("%d\n", sol.numRollsToTarget(n, k, target));
}