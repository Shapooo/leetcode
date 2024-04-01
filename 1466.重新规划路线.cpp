#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 *
 * [1466] 重新规划路线
 */

// @lc code=start
class Solution {
    int dfs(vector<vector<pair<int, bool>>>& graph, int cur, int pre)
    {
        int res = 0;
        for (auto& [next, isForward] : graph[cur]) {
            if (next == pre)
                continue;
            if (isForward)
                res++;
            res += dfs(graph, next, cur);
        }
        return res;
    }

public:
    int minReorder(int n, vector<vector<int>>& connections)
    {
        vector<vector<pair<int, bool>>> graph(n);
        for (auto& c : connections) {
            graph[c[0]].push_back({ c[1], true });
            graph[c[1]].push_back({ c[0], false });
        }
        return dfs(graph, 0, -1);
    }
};
// @lc code=end
