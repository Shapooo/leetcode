#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2316 lang=cpp
 *
 * [2316] 统计无向图中无法互相到达点对数
 */

// @lc code=start
class Solution {
    vector<vector<int>> nei {};
    vector<int> visit {};
    vector<int> graph {};
    int dfs(int vertex)
    {
        if (visit[vertex]) {
            return 0;
        }
        visit[vertex] = 1;
        int res = 1;
        for (auto& n : nei[vertex]) {
            res += dfs(n);
        }
        return res;
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges)
    {
        nei.resize(n);
        visit.resize(n);
        for (auto& v : edges) {
            nei[v[0]].push_back(v[1]);
            nei[v[1]].push_back(v[0]);
        }
        for (int i = 0; i < n; ++i) {
            int t = dfs(i);
            if (t) {
                graph.push_back(t);
            }
        }
        long long acc {}, res {};
        for (int i = 0; i < graph.size(); ++i) {
            res += acc * graph[i];
            acc += graph[i];
        }
        return res;
    }
};
// @lc code=end
