#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1726 lang=cpp
 *
 * [1726] 同积元组
 */

// @lc code=start
class Solution {
public:
    int tupleSameProduct(vector<int>& nums)
    {
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> freq {};
        for (int i = 0; i < n - 1; i++) {
            int a = nums[i];
            for (int j = i + 1; j < n; j++) {
                int val = a * nums[j];
                freq[val]++;
            }
        }
        for (auto& [k, v] : freq) {
            if (v > 1) {
                res += v * (v - 1) * 4;
            }
        }
        return res;
    }
};
// @lc code=end
