#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2593 lang=cpp
 *
 * [2593] 标记所有元素后数组的分数
 */

// @lc code=start
class Solution {
public:
    long long findScore(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> idices(n);
        for (int i = 1; i < n; ++i) {
            idices[i] = i;
        }
        stable_sort(idices.begin(), idices.end(), [&](int lhs, int rhs) { return nums[lhs] < nums[rhs]; });
        long long res {};
        unordered_set<int> marked {};
        for (auto i : idices) {
            if (marked.find(i) == marked.end()) {
                res += nums[i];
                marked.insert(i + 1);
                marked.insert(i - 1);
            }
        }
        return res;
    }
};
// @lc code=end
