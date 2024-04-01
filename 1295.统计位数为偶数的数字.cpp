#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1295 lang=cpp
 *
 * [1295] 统计位数为偶数的数字
 */

// @lc code=start
class Solution {
public:
    int findNumbers(vector<int>& nums)
    {
        int res {};
        for (auto& n : nums) {
            if (to_string(n).size() % 2 == 0) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
