#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2404 lang=cpp
 *
 * [2404] 出现最频繁的偶数元素
 */

// @lc code=start
class Solution {
public:
    int mostFrequentEven(vector<int>& nums)
    {
        unordered_map<int, int> m {};
        for (auto&& i : nums) {
            if (i % 2 == 0)
                m[i]++;
        }
        int res { -1 };
        int cnt { 0 };
        for (auto&& i : m) {
            if (i.second > cnt || i.second == cnt && i.first < res) {
                res = i.first;
                cnt = i.second;
            }
        }
        return res;
    }
};
// @lc code=end