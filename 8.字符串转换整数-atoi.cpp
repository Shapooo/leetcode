#include <climits>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s)
    {
        int size = s.size();
        long long result = 0;
        bool negative = 0;
        int index = 0;
        while (index < size && s[index] == ' ') {
            index++;
        }
        if (index == size) {
            return 0;
        }
        if (s[index] == '-' || s[index] == '+') {
            negative = s[index] == '-';
            index++;
        }
        while (index < size && s[index] == '0') {
            index++;
        }
        while (index < size && isdigit(s[index])) {
            result *= 10;
            result += s[index] - '0';
            if ((negative && -result <= INT_MIN) || (!negative && result >= INT_MAX)) {
                return negative ? INT_MIN : INT_MAX;
            }
            index++;
        }
        return negative ? -result : result;
    }
};
// @lc code=end
