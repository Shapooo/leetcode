#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */

// @lc code=start
class Solution {
    int helper(vector<int>& nums)
    {
        vector<vector<int>> mem(501, vector<int>(501, 0));
        int res { 2 };
        for (auto&& i : nums) {
            for (size_t j = 0; j <= i; j++) {
                mem[j][i] = mem[j][i - j] + 1;
                res = max(res, mem[j][i]);
            }
            for (size_t j = i + 1; 2 * j + i < 501; j++) {
                mem[j][i] = 1;
            }
        }

        return res;
    }

public:
    int longestArithSeqLength(vector<int>& nums)
    {
        int res = helper(nums);
        reverse(nums.begin(), nums.end());
        res = max(res, helper(nums));
        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution sol;
    vector<int> nums { 3, 6, 9, 12 };
    cout << sol.longestArithSeqLength(nums) << endl;

    nums = { 9, 4, 7, 2, 10 };
    cout << sol.longestArithSeqLength(nums) << endl;
    nums = { 20, 1, 15, 3, 10, 5, 8 };
    cout << sol.longestArithSeqLength(nums) << endl;
    return 0;
}
