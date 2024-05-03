#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1491 lang=cpp
 *
 * [1491] 去掉最低工资和最高工资后的工资平均值
 */

// @lc code=start
class Solution {
public:
    double average(vector<int>& salary)
    {
        int n = salary.size();
        int ma = *max_element(salary.begin(), salary.end()), mi = *min_element(salary.begin(), salary.end());
        return static_cast<double>(accumulate(salary.begin(), salary.end(), 0) - ma - mi) / (n - 2);
    }
};
// @lc code=end
