#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1929 lang=cpp
 *
 * [1929] 数组串联
 */

// @lc code=start
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums)
    {
        vector<int> copyyy = nums;
        for (auto& n : copyyy) {
            nums.push_back(n);
        }
        return nums;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> nums { 1, 2, 1 };
    sol.getConcatenation(nums);
}