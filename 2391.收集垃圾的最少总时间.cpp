#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2391 lang=cpp
 *
 * [2391] 收集垃圾的最少总时间
 */

// @lc code=start
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel)
    {
        int p {}, g {}, m {}, pending_p {}, pending_g {}, pending_m {};
        int n = garbage.size();
        for (int i = 0; i < n; ++i) {
            int p1 {}, g1 {}, m1 {};
            if (i > 0) {
                pending_g += travel[i - 1];
                pending_m += travel[i - 1];
                pending_p += travel[i - 1];
            }
            for (auto const& h : garbage[i]) {
                switch (h) {
                case 'P':
                    ++p1;
                    break;
                case 'G':
                    ++g1;
                    break;
                case 'M':
                    ++m1;
                    break;
                }
            }
            if (p1) {
                p += p1;
                p += pending_p;
                pending_p = 0;
            }
            if (g1) {
                g += g1;
                g += pending_g;
                pending_g = 0;
            }
            if (m1) {
                m += m1;
                m += pending_m;
                pending_m = 0;
            }
        }
        return p + g + m;
    }
};
// @lc code=end
