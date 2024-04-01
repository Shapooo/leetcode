#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1460 lang=cpp
 *
 * [1460] 通过翻转子数组使两个数组相等
 */

// @lc code=start
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr)
    {
        int a[1001] {};
        for (auto& n : target) {
            a[n]++;
        }
        for (auto& n : arr) {
            a[n]--;
        }
        for (int i = 1; i <= 1000; ++i) {
            if (a[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
