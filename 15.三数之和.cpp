#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int size = nums.size();
        vector<vector<int>> result {};
        sort(nums.begin(), nums.end());
        if (nums[0] > 0 || nums[size - 1] < 0) {
            return result;
        }

        int i = 0;
        for (int i = 0; i < size - 2; i++) {
            if (nums[i] > 0)
                return result;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1, k = size - 1;
            while (j < k) {
                auto target = nums[i] + nums[j] + nums[k];
                if (target > 0) {
                    k--;
                } else if (target < 0) {
                    j++;
                } else {
                    result.push_back({ nums[i], nums[j], nums[k] });
                    j++;
                    k--;
                    while (j < k && nums[j - 1] == nums[j])
                        j++;
                    while (j < k && nums[k + 1] == nums[k])
                        k--;
                }
            }
        }

        return result;
    }
};
// @lc code=end
