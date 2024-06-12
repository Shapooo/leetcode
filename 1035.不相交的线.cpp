#include <cstring>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    {
        int size1 = nums1.size(), size2 = nums2.size();
        int memo[size2];
        memset(memo, 0, sizeof(int) * size2);
        for (auto& n : nums1) {
            int prev = memo[0];
            memo[0] = (n == nums2[0]) || memo[0];
            for (int i = 1; i < size2; ++i) {
                int tmp = prev;
                prev = memo[i];
                memo[i] = (n == nums2[i]) ? tmp + 1 : max(memo[i], memo[i - 1]);
            }
        }
        return memo[size2 - 1];
    }
};
// @lc code=end
