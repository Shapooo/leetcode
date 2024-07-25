#include <cstdio>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=2844 lang=cpp
 *
 * [2844] 生成特殊数字的最少操作
 */

// @lc code=start
class Solution {
  public:
    int minimumOperations(string num) {
        int n = num.size();
        long long lfive = num.find_last_of('5');
        long long ltwo = lfive == -1 ? -1 : num.find_last_of('2', lfive);
        long long lseven = lfive == -1 ? -1 : num.find_last_of('7', lfive);
        long long lzero = num.find_last_of('0');
        long long lzfive = lzero == -1 ? -1 : num.find_last_of('5', lzero);
        long long lhan =
            lzero == -1 || lzero == 0 ? -1 : num.find_last_of('0', lzero - 1);
        long long res = max(lhan, max(lseven, max(lzfive, ltwo)));
        // printf("%lld %lld %lld\n", lzero, res, lhan);
        if (res == -1) {
            if (lzero != -1) {
                return n - 1;
            } else {
                return n;
            }
        }
        return n - res - 2;
    }
};
// @lc code=end

int main() {
    Solution sol{};
    string num{"0"};
    sol.minimumOperations(num);
    return 0;
}