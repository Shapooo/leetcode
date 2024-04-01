#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2605 lang=cpp
 *
 * [2605] 从两个数字数组里生成最小数字
 */

// @lc code=start
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2)
    {
        int a[10] {};
        for (auto n : nums1) {
            a[n]++;
        }
        int b[10] {};
        for (auto n : nums2) {
            b[n]++;
        }
        for (int i = 1; i < 10; ++i) {
            if (a[i] && b[i]) {
                return i;
            }
        }
        int mina = 0;
        for (int i = 1; i < 10; ++i) {
            if (a[i]) {
                mina = i;
                break;
            }
        }
        int minb = 0;
        for (int i = 1; i < 10; ++i) {
            if (b[i]) {
                minb = i;
                break;
            }
        }

        return mina < minb ? mina * 10 + minb : minb * 10 + mina;
    }
};
// @lc code=end
