#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2961 lang=cpp
 *
 * [2961] 双模幂运算
 */

// @lc code=start
class Solution {
  public:
    vector<int> getGoodIndices(vector<vector<int>> &variables, int target) {
        vector<int> res{};
        int n = variables.size();
        for (int i = 0; i < n; ++i) {
            int tmp = 1;
            for (int j = 0; j < variables[i][1]; ++j) {
                tmp *= variables[i][0];
                tmp %= 10;
            }
            int r = 1;
            for (int j = 0; j < variables[i][2]; ++j) {
                r *= tmp;
                r %= variables[i][3];
            }
            if (r == target) {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end
