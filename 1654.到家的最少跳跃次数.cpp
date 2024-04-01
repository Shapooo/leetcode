#include <cstdio>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1654 lang=cpp
 *
 * [1654] 到家的最少跳跃次数
 */

// @lc code=start
// class Solution {
//     int lcd(int a, int b)
//     {
//         if (a == 1 || b == 1) {
//             return 1;
//         }
//         while (b) {
//             int t = a % b;
//             a = b;
//             b = t;
//         }
//         return a;
//     }

//     int calc(int mod, int d, int k)
//     {
//         for (int i = 0; i < mod; ++i) {
//             if (d * i % mod == k) {
//                 return i;
//             }
//         }
//         return 0;
//     }

// public:
//     int minimumJumps(vector<int>& forbidden, int a, int b, int x)
//     {
//         vector<int> dp(4000, 0);
//         for (auto n : forbidden) {
//             dp[n] = -1;
//         }
//         // for (int i = a; i < x + a; i += a) {
//         //     dp[i] = i / a;
//         // }

//         int res = -1;
//         if (dp[x]) {
//             res = dp[x];
//         }
//         if (dp[x + b] > 0) {
//             res = min(dp[x], dp[x + b] + 1);
//         }
//         if (a < b) {
//             if (lcd(a, b) == 1) {
//                 for (int i = x + 1; i < x + a; i++) {
//                     if (dp[i] > 0) {
//                         int a = calc(a, 2 * a - b, i);
//                         int step = dp[i] + a * 2 + (a * (b - a) + a - 1) / a;
//                         if (res == -1) {
//                             res = step;
//                         } else {
//                             res = min(res, step);
//                         }
//                     }
//                 }
//             } else {
//                 int d = b - a;
//                 for (int i = x + d; i < x + a; i += d) {
//                     if (dp[i] > 0) {
//                         int step = dp[i] + (i - x) / d * 2;
//                         if (res == -1) {
//                             res = step;
//                         } else {
//                             res = min(res, step);
//                         }
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };
struct Solution {
    int abs(int a)
    {
        return a < 0 ? -a : a;
    }

public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x)
    {
        unordered_set<int> forb {};
        for (auto n : forbidden) {
            forb.insert(n);
        }
        queue<pair<int, int>> q {};
        q.push({ 0, 0 });
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p.first == x) {
                return abs(p.second);
            }
            if (forb.find(p.first + a) == forb.end() && abs(p.second) + 1 < 3 * a + x / a + 1) {
                q.push({ p.first + a, abs(p.second) + 1 });
            }
            if (p.first - b > 0 && p.second > 0 && forb.find(p.first - b) == forb.end()) {
                q.push({ p.first - b, -p.second - 1 });
            }
        }
        return -1;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> forbidden { 14, 4, 18, 1, 15 };
    int a = 3, b = 15, x = 9;
    sol.minimumJumps(forbidden, a, b, x);
}