#include <bitset>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
    bitset<2001> visited {};
    bitset<2001> path {};
    bool dfs(vector<vector<int>>& pres, int id, vector<int>& res)
    {
        if (path[id]) {
            return false;
        }
        if (visited[id]) {
            return true;
        }
        visited[id] = 1;
        if (pres[id].empty()) {
            res.push_back(id);
            return true;
        }
        path[id] = 1;
        for (auto& c : pres[id]) {
            if (!dfs(pres, c, res)) {
                return false;
            }
        }
        path[id] = 0;
        res.push_back(id);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> res {};
        vector<vector<int>> pres(numCourses);
        for (auto& v : prerequisites) {
            pres[v[0]].emplace_back(v[1]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(pres, i, res)) {
                return {};
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    int numCourses = 2;
    vector<vector<int>> prerequisites { { 0, 1 }, { 1, 0 } };
    sol.findOrder(numCourses, prerequisites);
}