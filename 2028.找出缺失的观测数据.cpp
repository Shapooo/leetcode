#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 *
 * [2028] 找出缺失的观测数据
 */

// @lc code=start
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {
        int sum = accumulate(rolls.begin(), rolls.end(), 0), m = rolls.size();
        int target = (m + n) * mean - sum;
        int maj = target / n, rem = target % n;
        if (maj > 6 || maj < 1 || maj == 6 && rem) {
            return {};
        }
        vector<int> res(n - rem, maj);
        res.resize(n, maj + 1);
        return res;
    }
};
// @lc code=end
