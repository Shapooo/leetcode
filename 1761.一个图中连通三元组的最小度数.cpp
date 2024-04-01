#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1761 lang=cpp
 *
 * [1761] 一个图中连通三元组的最小度数
 */

// @lc code=start
class Solution {
    int deg(vector<vector<int>>& neigh, vector<int>& path)
    {
        int res = 0;
        for (auto i : path) {
            res += neigh[i].size();
        }
        return res - 6;
    }

    int ternary(vector<vector<int>>& neigh, vector<int>& path)
    {
        if (path.size() == 3) {
            if (binary_search(neigh[path[2]].begin(), neigh[path[2]].end(), path[0]))
                return deg(neigh, path);
            return 1'000'000'000;
        }
        int b = path.back();
        int res = 1'000'000'000;
        auto it = upper_bound(neigh[b].begin(), neigh[b].end(), b);
        for (; it != neigh[b].end(); ++it) {
            path.push_back(*it);
            res = min(res, ternary(neigh, path));
            path.pop_back();
        }
        return res;
    }

public:
    int
    minTrioDegree(int n, vector<vector<int>>& edges)
    {

        vector<vector<int>> neigh(n + 1);
        for (auto& e : edges) {
            neigh[e[0]].push_back(e[1]);
            neigh[e[1]].push_back(e[0]);
        }
        for (auto& v : neigh) {
            sort(v.begin(), v.end());
        }

        int res = 1'000'000'000;
        for (int i = 1; i <= n; ++i) {
            vector<int> path { i };
            int t = ternary(neigh, path);
            res = min(res, t);
        }
        return res == 1'000'000'000 ? -1 : res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    int n = 6;
    vector<vector<int>> edges { { 5, 2 }, { 4, 1 }, { 4, 2 }, { 1, 5 } };
    sol.minTrioDegree(n, edges);
}
