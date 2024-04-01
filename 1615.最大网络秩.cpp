#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1615 lang=cpp
 *
 * [1615] 最大网络秩
 */

// @lc code=start
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        vector<unordered_set<int>> neigh(n);
        for (auto& r : roads) {
            neigh[r[0]].insert(r[1]);
            neigh[r[1]].insert(r[0]);
        }
        vector<int> cs(n);
        for (int i = 0; i < n; ++i) {
            cs[i] = i;
        }
        sort(cs.begin(), cs.end(), [&neigh](int l, int r) {
            return neigh[l].size() > neigh[r].size();
        });
        int res = 0;
        if (neigh[cs[0]].size() == neigh[cs[1]].size()) {
            bool flag = false;
            vector<int> fcv { cs[0], cs[1] };
            for (int i = 2; i < n && neigh[cs[i]].size() == neigh[cs[0]].size(); ++i) {
                fcv.push_back(cs[i]);
            }
            int m = fcv.size();
            for (int i = 0; i < m - 1; ++i) {
                for (int j = i + 1; j < m; ++j) {
                    if (neigh[fcv[i]].find(fcv[j]) == neigh[fcv[i]].end()) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                res = neigh[cs[0]].size() * 2;
            } else {
                res = neigh[cs[0]].size() * 2 - 1;
            }
        } else {
            int ma_city = cs[0];
            vector<int> sc { cs[1] };
            int idx = 1;
            int flag = false;
            while (idx < n && neigh[cs[idx]].size() == neigh[cs[1]].size()) {
                if (neigh[ma_city].find(cs[idx]) == neigh[ma_city].end()) {
                    flag = true;
                    break;
                }
                idx++;
            }
            if (flag) {
                res = neigh[ma_city].size() + neigh[cs[1]].size();
            } else {
                res = neigh[ma_city].size() + neigh[cs[1]].size() - 1;
            }
        }
        return res;
    }
};
// @lc code=end