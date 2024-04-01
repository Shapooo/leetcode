#include <array>
#include <bitset>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2470 lang=cpp
 *
 * [2470] 最小公倍数为 K 的子数组数目
 */

// @lc code=start
constexpr bitset<1000> calc_factors(int n)
{
    bitset<1000> factors {};
    int factor = 2;
    while (n > 1) {
        if (n % factor == 0) {
            factors[factor] = 1;
        }
        while (n % factor == 0) {
            n /= factor;
        }
    }
    return factors;
}
class Solution {

public:
    int subarrayLCM(vector<int>& nums, int k)
    {
        // constexpr array<bitset<1000>, 1001> a {
        //     []() {
        //         array<bitset<1000>, 1001> a {};
        //         for (int i = 2; i <= 1000; ++i) {
        //             int b = 2;
        //             int t = i;
        //             while (t > 1) {
        //                 if (t % b == 0) {
        //                     a[i][b] = 1;
        //                 }
        //                 while (t % b == 0) {
        //                     t /= b;
        //                 }
        //                 b += 1;
        //             }
        //         }
        //         return a;
        //     }()
        // };
        array<bitset<1000>, 1001> a {};
        a[1][1] = 1;
        for (int i = 2; i <= 1000; ++i) {
            int b = 2;
            int t = i;
            while (t > 1) {
                if (t % b == 0) {
                    a[i][b] = 1;
                }
                while (t % b == 0) {
                    t /= b;
                }
                b += 1;
            }
        }
        int n = nums.size(); {
            
        }
        return {};
    }
};
// @lc code=end
