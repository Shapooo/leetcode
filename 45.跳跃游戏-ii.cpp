#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int result = 0;
        int size = nums.size();
        if (size == 1) {
            return 0;
        }
        int farest = 0;
        int bound = 0;
        for (int i = 0; i < size; ++i) {
            if (i > bound) {
                result++;
                bound = farest;
            }
            farest = max(farest, nums[i] + i);
            if (farest >= size - 1) {
                break;
            }
        }
        return result + 1;
    }
};
// @lc code=end
