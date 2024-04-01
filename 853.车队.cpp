#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=853 lang=cpp
 *
 * [853] 车队
 */

// @lc code=start
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        int n = position.size();
        vector<int> idx(n);
        for (int i = 0; i < n; ++i) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int lhs, int rhs) {
            return position[lhs] > position[rhs];
        });
        int res { 1 };
        double arrive = (double)(target - position[idx[0]]) / speed[idx[0]];
        for (int i = 1; i < n; ++i) {
            double arr = (double)(target - position[idx[i]]) / speed[idx[i]];
            if (arr > arrive) {
                res++;
                arrive = arr;
            }
        }
        return res;
    }
};
// @lc code=end
