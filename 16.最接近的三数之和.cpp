#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int minDiff = 10e5;
        int result;

        for (int i = 0; i < size - 2; ++i) {
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            int tmp = nums[i] + nums[i + 1] + nums[i + 2];
            if (tmp > target) {
                if (minDiff > tmp - target) {
                    result = tmp;
                    minDiff = tmp - target;
                }
                continue;
            }
            tmp = nums[i] + nums[size - 2] + nums[size - 1];
            if (tmp < target) {
                if (minDiff > target - tmp) {
                    result = tmp;
                    minDiff = target - tmp;
                }
                continue;
            }
            int left = i + 1, right = size - 1;
            while (left < right) {
                int tmp = nums[i] + nums[left] + nums[right];
                if (abs(target - tmp) < minDiff) {
                    minDiff = abs(target - tmp);
                    result = tmp;
                }
                if (tmp > target) {
                    right--;
                    while (right > left && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (tmp < target) {
                    left++;
                    while (right > left && nums[left] == nums[left - 1]) {
                        left++;
                    }
                } else {
                    return result;
                }
            }
        }
        return result;
    }
};
// @lc code=end
