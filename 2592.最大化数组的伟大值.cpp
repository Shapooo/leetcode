#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2592 lang=cpp
 *
 * [2592] 最大化数组的伟大值
 */

// @lc code=start
class Solution {
public:
    int maximizeGreatness(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        auto len = nums.size();
        int res {};
        int idx = len - 1;
        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] < nums[idx]) {
                res++;
                idx--;
            }
        }

        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution sol;
    vector<int> nums { 1, 3, 5, 2, 1, 3, 1 };
    cout << sol.maximizeGreatness(nums) << endl;
    nums = { 1, 2, 3, 4 };
    cout << sol.maximizeGreatness(nums) << endl;
    return 0;
}