#include <bitset>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */

// @lc code=start
class Solution {
    int _result {};
    bitset<16> _nums {};

public:
    int countArrangement(int n)
    {
        bitset<16> nums {};
        backtrace(1, n);
        return _result;
    }
    void backtrace(int curNum, int maxNum)
    {
        if (curNum > maxNum) {
            _result++;
        }
        for (int i = 1; i <= maxNum; ++i) {
            if (!_nums[i] && (!(curNum % i) || !(i % curNum))) {
                _nums[i] = 1;
                backtrace(curNum + 1, maxNum);
                _nums[i] = 0;
            }
        }
    }
};
// @lc code=end
