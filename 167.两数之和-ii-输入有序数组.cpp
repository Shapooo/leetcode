#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        auto len = numbers.size();
        int l = 0, r = len - 1;
        while (l < r) {
            auto tmp = numbers[l] + numbers[r];
            if (tmp == target) {
                return { l + 1, r + 1 };
            } else if (tmp < target) {
                l++;
            } else {
                r--;
            }
        }
        return {};
    }
};
// @lc code=end
