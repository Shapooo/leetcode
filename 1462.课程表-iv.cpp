#include <bitset>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1462 lang=cpp
 *
 * [1462] 课程表 IV
 */

// @lc code=start
class Solution {
    bool dfs(int course, int target, vector<vector<int>>& pre, bitset<101>& visited)
    {
        if (visited[course]) {
            return false;
        }
        visited[course] = 1;
        for (auto& n : pre[course]) {
            if (n == target) {
                return true;
            }
            if (dfs(n, target, pre, visited)) {
                return true;
            }
        }
        return false;
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        vector<vector<int>> pre(numCourses);
        for (auto& p : prerequisites) {
            pre[p[1]].push_back(p[0]);
        }
        int n = queries.size();
        vector<bool> res(n);
        for (int i = 0; i < n; ++i) {
            bitset<101> visited {};
            res[i] = dfs(queries[i][1], queries[i][0], pre, visited);
        }
        return res;
    }
};
// @lc code=end
