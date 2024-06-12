#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        int size1 = nums1.size(), size2 = nums2.size();
        vector<int> memo(size2);
        int result = 0;
        for (auto& i : nums1) {
            for (int j = size2 - 1; j > 0; --j) {
                memo[j] = nums2[j] == i ? memo[j - 1] + 1 : 0;
                result = max(result, memo[j]);
            }
            memo[0] = nums2[0] == i;
            result = max(result, memo[0]);
        }
        return result;
    }
};
// @lc code=end
