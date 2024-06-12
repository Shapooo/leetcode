#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        int result {};
        int size = nums.size();
        sort(nums.begin(), nums.end());
        if (k > size) {
            if (k - size % 2) {
                k = size - 1;
            } else {
                k = size;
            }
        }
        for (int i = 0; i < size; ++i) {
            if (k > 0) {
                if (nums[i] >= 0) {
                    if (k % 2) {
                        if (i == 0) {
                            result -= nums[i];
                        } else {
                            result += abs(nums[i - 1] + nums[i]) + nums[i - 1];
                        }
                    } else {
                        result += nums[i];
                    }
                    k = 0;
                } else {
                    result -= nums[i];
                    --k;
                }
            } else {
                result += nums[i];
            }
        }
        return result;
    }
};
// @lc code=end
