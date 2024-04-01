#include <algorithm>
#include <bitset>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1583 lang=cpp
 *
 * [1583] 统计不开心的朋友
 */

// @lc code=start
class Solution {
    bool help(vector<vector<int>>& transpref, vector<vector<int>>& preferences, vector<int>& pair_fri, int a, int b)
    {
        auto& p = preferences[a];
        for (int i = 0; i < transpref[a][b]; ++i) {
            int cur_f = preferences[a][i];
            int cur_ff = pair_fri[cur_f];
            if (transpref[cur_f][a] < transpref[cur_f][cur_ff]) {
                return true;
            }
        }
        return false;
    }

public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs)
    {
        vector<int> pair_fri(n, -1);
        for (auto& v : pairs) {
            pair_fri[v[0]] = v[1];
            pair_fri[v[1]] = v[0];
        }
        vector<vector<int>> transpref(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                transpref[i][preferences[i][j]] = j;
            }
        }
        bitset<500> unhappy {};
        for (auto& v : pairs) {
            if (!unhappy[v[0]] && help(transpref, preferences, pair_fri, v[0], v[1])) {
                unhappy[v[0]] = 1;
            }
            if (!unhappy[v[1]] && help(transpref, preferences, pair_fri, v[1], v[0])) {
                unhappy[v[1]] = 1;
            }
        }
        int res {};
        for (int i = 0; i < n; ++i) {
            if (unhappy[i])
                res++;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    int n = 2;
    vector<vector<int>> preferences { { 1 }, { 0 } }, pairs { { 1, 0 } };
    sol.unhappyFriends(n, preferences, pairs);
}