#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings)
    {
        int result = 0;
        int size = ratings.size();
        if (size == 1) {
            return 1;
        }
        vector<int> candyVec(size, 1);

        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candyVec[i] = candyVec[i - 1] + 1;
            }
        }
        for (int i = size - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i] && candyVec[i] >= candyVec[i - 1]) {
                candyVec[i - 1] = candyVec[i] + 1;
            }
            result += candyVec[i];
        }
        return result + candyVec[0];
    }
};
// @lc code=end
