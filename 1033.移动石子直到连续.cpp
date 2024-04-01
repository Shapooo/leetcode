#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1033 lang=cpp
 *
 * [1033] 移动石子直到连续
 */

// @lc code=start
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        vector<int> vec { a, b, c }, res(2);
        sort(vec.begin(), vec.end());
        if (vec[0] == vec[1] - 1 && vec[1] == vec[2] - 1) {
            return { 0, 0 };
        }
        if (vec[0] == vec[1] - 1 || vec[1] == vec[2] - 1 || vec[1] == vec[2] - 2 || vec[0] == vec[1] - 2) {
            res[0] = 1;
        } else {
            res[0] = 2;
        }
        res[1] = vec[2] - vec[0] - 2;

        return res;
    }
};
// @lc code=end
