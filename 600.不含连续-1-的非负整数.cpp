#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=600 lang=cpp
 *
 * [600] 不含连续1的非负整数
 */

// @lc code=start
// class Solution {
//   public:
//     int findIntegers(int n) {
//         if (n == 1) {
//             return 2;
//         }
//         vector<int> res{0, 1};
//         int e = 2;
//         int l = 0;
//         while (e <= n) {
//             int r = res.size();
//             for (int i = l; i < r; ++i) {
//                 if ((e | res[i]) > n || (e >> 1) & res[i]) {
//                     break;
//                 }
//                 res.push_back(e | res[i]);
//             }
//             e <<= 1;
//         }
//         return res.size();
//     }
// };

class Solution {
    int help(int n, int b) {
        int res = 1;
        if (n && n << 1 <= b) {
            res += help(n << 1, b);
        }
        if ((n & 1) == 0 && (n << 1 | 1) <= b) {
            res += help((n << 1) | 1, b);
        }
        return res;
    }

  public:
    int findIntegers(int n) { return help(0, n); }
};
// @lc code=end
