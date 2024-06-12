#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        vector<int> result(size);
        for (int i = 0; i < size; ++i) {
            result[i] = bin_search(tmp, size, nums[i]);
        }
        return result;
    }
    int bin_search(vector<int>& nums, int size, int v)
    {
        int l = 0, r = size;
        while (l < r) {
            int m = (r + l) / 2;
            if (nums[m] == v) {
                while (m > 0 && nums[m - 1] == v) {
                    --m;
                }
                return m;
            } else if (nums[m] > v) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
// @lc code=end
