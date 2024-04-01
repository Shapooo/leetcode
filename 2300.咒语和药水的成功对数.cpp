#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */

// @lc code=start
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        vector<int> res {};
        sort(potions.begin(), potions.end());
        for (auto& s : spells) {
            auto it = lower_bound(potions.begin(), potions.end(), (success + s - 1) / s);
            res.push_back(potions.end() - it);
        }
        return res;
    }
};
// @lc code=end
