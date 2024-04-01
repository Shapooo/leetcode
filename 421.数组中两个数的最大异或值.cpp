#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
class Solution {
public:
    int findMaximumXOR(vector<int>& nums)
    {
        int res {};
        for (int i = 30; i >= 0; --i) {
            unordered_set<int> s;
            for (auto& n : nums) {
                s.insert(n >> i);
            }
            res = res * 2 + 1;
            bool found = false;
            for (auto& n : nums) {
                if (s.count(res ^ (n >> i))) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                res -= 1;
            }
        }
        return res;
    }
};
// @lc code=end
