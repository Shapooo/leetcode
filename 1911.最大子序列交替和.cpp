#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1911 lang=cpp
 *
 * [1911] 最大子序列交替和
 */

// @lc code=start
typedef long long ll;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums)
    {
        auto len = nums.size();
        pair<ll, ll> a { nums[0], 0 };

        for (int i = 1; i < len; ++i) {
            pair<ll, ll> tmp { max(a.first, a.second + nums[i]), max(a.second, a.first - nums[i]) };
            a = tmp;
        }
        cout << a.first << ' ' << a.second << endl;
        return a.first;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> nums = { 4, 2, 5, 3 };
    cout << sol.maxAlternatingSum(nums) << endl;
    nums = { 5, 6, 7, 8 };
    cout << sol.maxAlternatingSum(nums) << endl;
    nums = { 6, 2, 1, 2, 4, 5 };
    cout << sol.maxAlternatingSum(nums) << endl;
    nums = { 4, 9, 7, 4, 8 };
    cout << sol.maxAlternatingSum(nums) << endl;
}