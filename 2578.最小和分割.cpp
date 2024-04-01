#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2578 lang=cpp
 *
 * [2578] 最小和分割
 */

// @lc code=start
class Solution {
public:
    int splitNum(int num)
    {
        vector<int> bits;
        while (num) {
            bits.push_back(num % 10);
            num /= 10;
        }
        sort(bits.begin(), bits.end());
        int n = bits.size();
        int a {}, b {};
        for (int i = 0; i < n; ++i) {
            if (i % 2) {
                a *= 10;
                a += bits[i];
            } else {
                b *= 10;
                b += bits[i];
            }
        }
        return a + b;
    }
};
// @lc code=end
