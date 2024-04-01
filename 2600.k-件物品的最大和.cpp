/*
 * @lc app=leetcode.cn id=2600 lang=cpp
 *
 * [2600] K 件物品的最大和
 */

// @lc code=start
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
    {
        if (k <= numOnes) {
            return k;
        } else if (k <= numOnes + numZeros) {
            return numOnes;
        } else {
            return 2 * numOnes - k + numZeros;
        }
    }
};
// @lc code=end
