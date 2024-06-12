#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> map;
        for (auto i : nums) {
            map[i]++;
        }

        priority_queue<pair<int, int>> q;
        for (auto& p : map) {
            q.push({ p.second, p.first });
        }

        vector<int> result {};
        for (int i = 0; i < k; i++) {
            result.push_back(q.top().second);
            q.pop();
        }
        return result;
    }
};
// @lc code=end
