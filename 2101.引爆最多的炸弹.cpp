#include <algorithm>
#include <bitset>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2101 lang=cpp
 *
 * [2101] 引爆最多的炸弹
 */

// @lc code=start
class Solution {
    long long square(int x) { return (long long)x * x; }

    void dfs(vector<vector<int>> &neibor, bitset<128> &visited, int x) {
        if (visited[x]) {
            return;
        }
        visited[x] = 1;
        for (auto const &n : neibor[x]) {
            dfs(neibor, visited, n);
        }
    }

  public:
    int maximumDetonation(vector<vector<int>> &bombs) {
        int n = bombs.size();
        vector<vector<int>> neibor(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                auto dis = square(bombs[i][0] - bombs[j][0]) +
                           square(bombs[i][1] - bombs[j][1]);
                if (dis <= square(bombs[i][2])) {
                    neibor[i].push_back(j);
                }
            }
        }
        int res{};
        for (int i = 0; i < n; ++i) {
            bitset<128> visited{};
            dfs(neibor, visited, i);
            res = max(res, (int)visited.count());
        }

        return res;
    }
};
// @lc code=end

int main() {
    Solution sol{};
    vector<vector<int>> bombs{{2, 1, 3}, {6, 1, 4}};
    // sol.maximumDetonation(bombs);
    bombs = {{855, 82, 158},  {17, 719, 430},  {90, 756, 164},  {376, 17, 340},
             {691, 636, 152}, {565, 776, 5},   {464, 154, 271}, {53, 361, 162},
             {278, 609, 82},  {202, 927, 219}, {542, 865, 377}, {330, 402, 270},
             {720, 199, 10},  {986, 697, 443}, {471, 296, 69},  {393, 81, 404},
             {127, 405, 177}};
    bombs = {{1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4}};
    sol.maximumDetonation(bombs);
    return {};
}