#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        auto max_it = max_element(nums.begin(), nums.end());
        int max_idx = max_it - nums.begin();
        int size = nums.size();
        stack<int> stk {};
        stk.push(nums[max_idx]);
        vector<int> result(size);
        result[max_idx] = -1;
        for (int i = max_idx - 1; i >= 0; --i) {
            while (!stk.empty() && nums[i] >= stk.top()) {
                stk.pop();
            }
            if (stk.empty()) {
                result[i] = -1;
            } else {
                result[i] = stk.top();
            }
            stk.push(nums[i]);
        }
        for (int i = size - 1; i > max_idx; --i) {
            while (!stk.empty() && nums[i] >= stk.top()) {
                stk.pop();
            }
            if (stk.empty()) {
                result[i] = -1;
            } else {
                result[i] = stk.top();
            }
            stk.push(nums[i]);
        }
        return result;
    }
};
// @lc code=end
