#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2225 lang=cpp
 *
 * [2225] 找出输掉零场或一场比赛的玩家
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        unordered_map<int, int> lose {};
        unordered_set<int> win {};
        for (auto const& m : matches) {
            if (lose.find(m[0]) == lose.end()) {
                win.insert(m[0]);
            }
            auto it = win.find(m[1]);
            if (it != win.end()) {
                win.erase(it);
            }
            lose[m[1]]++;
        }
        vector<int> ans0 { win.begin(), win.end() }, ans1 {};
        for (auto const& [k, v] : lose) {
            if (v == 1) {
                ans1.push_back(k);
            }
        }
        sort(ans0.begin(), ans0.end());
        sort(ans1.begin(), ans1.end());
        return { ans0, ans1 };
    }
};
// @lc code=end
