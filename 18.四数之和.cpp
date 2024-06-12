#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> result {};
        int size = nums.size();
        sort(nums.begin(), nums.end());

        if (size < 4 || static_cast<long>(nums[size - 4]) + nums[size - 3] + nums[size - 2] + nums[size - 1] < target) {
            return result;
        }

        for (int i = 0; i < size - 3; ++i) {
            if (static_cast<long>(nums[i]) + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if (static_cast<long>(nums[i]) + nums[size - 3] + nums[size - 2] + nums[size - 1] < target) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < size - 2; ++j) {
                if (static_cast<long>(nums[i]) + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if (static_cast<long>(nums[i]) + nums[j] + nums[size - 2] + nums[size - 1] < target) {
                    continue;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int l = j + 1, r = size - 1;
                while (l < r) {
                    long tmp = static_cast<long>(nums[i]) + nums[j] + nums[l] + nums[r];
                    if (tmp > target) {
                        r--;
                    } else if (tmp < target) {
                        l++;
                    } else {
                        result.push_back({ nums[i], nums[j], nums[l], nums[r] });
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                        while (l < r && nums[r] == nums[r + 1])
                            r--;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
