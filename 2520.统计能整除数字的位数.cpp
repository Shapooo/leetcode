/*
 * @lc app=leetcode.cn id=2520 lang=cpp
 *
 * [2520] 统计能整除数字的位数
 */

// @lc code=start
class Solution {
public:
    int countDigits(int num)
    {
        int res {}, map[10] {}, n = num;
        while (n) {
            map[n % 10]++;
            n /= 10;
        }
        for (int i = 1; i < 10; i++) {
            if (map[i] && num % i == 0) {
                res += map[i];
            }
        }
        return res;
    }
};
// @lc code=end
