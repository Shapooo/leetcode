#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2216 lang=cpp
 *
 * [2216] 美化数组的最少删除数
 */

// @lc code=start
class Solution {
public:
    int minDeletion(vector<int>& nums)
    {
        int n = nums.size();
        int res { 0 };
        for (int i = 0; i < n;) {
            if (i + 1 == n) {
                res++;
                break;
            }
            if (nums[i] == nums[i + 1]) {
                res++;
                i++;
            } else {
                i += 2;
            }
        }
        return res;
    }
};
// @lc code=end
