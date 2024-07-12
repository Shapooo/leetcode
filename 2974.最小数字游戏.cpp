#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=2974 lang=cpp
 *
 * [2974] 最小数字游戏
 */

// @lc code=start
class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        vector<int> arr(nums);
        int n = nums.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i += 2)
        {
            swap(arr[i], arr[i + 1]);
        }
        return arr;
    }
};
// @lc code=end
