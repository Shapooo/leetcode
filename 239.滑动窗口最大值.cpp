#include <deque>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if (k == 1) {
            return nums;
        }
        vector<int> result {};
        deque<int> dq {};
        int l = 0, r = 1;
        int size = nums.size();
        dq.push_back(nums[0]);
        while (r < k) {
            while (!dq.empty() && nums[r] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[r]);
            r++;
        }
        result.push_back(dq.front());
        while (r < size) {
            if (nums[l] == dq.front()) {
                dq.pop_front();
            }
            l++;
            while (!dq.empty() && nums[r] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[r]);
            r++;

            result.push_back(dq.front());
        }
        return result;
    }
};
// @lc code=end
