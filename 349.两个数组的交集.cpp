#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> set {};
        vector<int> result {};
        for (auto i : nums1) {
            set.emplace(i);
        }
        for (auto i : nums2) {
            auto iter = set.find(i);
            if (iter != set.end()) {
                result.push_back(*iter);
                set.erase(iter);
            }
        }
        return result;
    }
};
// @lc code=end
