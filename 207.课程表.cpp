#include <bitset>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
    bitset<2001> checked {};
    bool check(vector<vector<int>>& courseDependencies, bitset<2001>& path, int id)
    {
        if (path[id]) {
            return false;
        }
        bool res = true;
        path[id] = 1;
        for (auto& n : courseDependencies[id]) {
            if (!checked[n]) {
                if (!check(courseDependencies, path, n)) {
                    res = false;
                    break;
                }
            }
        }
        path[id] = 0;
        checked[id] = 1;

        return res;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> courseDependencies(numCourses);
        for (auto& v : prerequisites) {
            courseDependencies[v[0]].push_back(v[1]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!checked[i]) {
                bitset<2001> path {};
                if (!check(courseDependencies, path, i)) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
