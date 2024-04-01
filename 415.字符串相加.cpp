#include <algorithm>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res {};
        int idx {};
        int cin {};
        auto len1 = num1.size(), len2 = num2.size(), len = min(len1, len2);
        while (idx < len) {
            int tmp = cin + num1[idx] + num2[idx] - 2 * '0';
            res.push_back(tmp % 10 + '0');
            cin = tmp / 10;
            idx++;
        }
        while (idx < len1) {
            int tmp = cin + num1[idx] - '0';
            res.push_back(tmp % 10 + '0');
            cin = tmp / 10;
            idx++;
        }
        while (idx < len2) {
            int tmp = cin + num2[idx] - '0';
            res.push_back(tmp % 10 + '0');
            cin = tmp / 10;
            idx++;
        }
        if (cin) {
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
