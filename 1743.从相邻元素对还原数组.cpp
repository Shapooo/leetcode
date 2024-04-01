#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1743 lang=cpp
 *
 * [1743] 从相邻元素对还原数组
 */

// @lc code=start
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs)
    {
        unordered_map<int, vector<int>> adj_map {};
        int n = adjacentPairs.size() + 1;
        for (auto& adj : adjacentPairs) {
            adj_map[adj[0]].push_back(adj[1]);
            adj_map[adj[1]].push_back(adj[0]);
        }
        int start = 0;
        for (auto& p : adj_map) {
            if (p.second.size() == 1) {
                start = p.first;
                break;
            }
        }
        vector<int> res { start, adj_map[start][0] };
        for (int i = 2; i < n; ++i) {
            auto& a = adj_map[res[i - 1]];
            if (a[0] != res[i - 2]) {
                res.push_back(a[0]);
            } else {
                res.push_back(a[1]);
            }
        }
        return res;
    }
};
// @lc code=end
