#include <bitset>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1443 lang=cpp
 *
 * [1443] 收集树上所有苹果的最少时间
 */

// @lc code=start
class Solution {
    bitset<100'000> accessed {};
    bool help(vector<vector<int>>& neigh, vector<bool>& hasApple, int id, int& count)
    {
        int res {};
        bool ha = hasApple[id];
        accessed[id] = 1;
        for (auto n : neigh[id]) {
            if (accessed[n]) {
                continue;
            }
            int cn = 0;
            bool na = help(neigh, hasApple, n, cn);
            if (na) {
                res += cn;
            }
        }
        accessed[id] = 0;
        if (res || ha) {
            count = res + 2;
            return true;
        } else {
            return false;
        }
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
    {
        vector<vector<int>> neigh(n);
        for (auto& e : edges) {
            neigh[e[0]].push_back(e[1]);
            neigh[e[1]].push_back(e[0]);
        }
        int res = 0;
        accessed[0] = 1;
        help(neigh, hasApple, 0, res);
        return max(0, res - 2);
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<vector<int>> edges;
    int n;
    vector<bool> hasApple;
    n = 7, edges = { { 0, 1 }, { 0, 2 }, { 1, 4 }, { 1, 5 }, { 2, 3 }, { 2, 6 } }, hasApple = { false, false, true, false, true, true, false };
    sol.minTime(n, edges, hasApple);
}