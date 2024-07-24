#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2766 lang=cpp
 *
 * [2766] 重新放置石块
 */

// @lc code=start
class Solution {
  public:
    vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom,
                                vector<int> &moveTo) {
        unordered_set<int> S(nums.begin(), nums.end());
        int n = moveFrom.size();
        for (int i = 0; i < n; ++i) {
            auto it = S.find(moveFrom[i]);
            if (it != S.end()) {
                S.erase(it);
                S.insert(moveTo[i]);
            }
        }
        vector<int> res(S.begin(), S.end());
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
