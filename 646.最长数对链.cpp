#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        vector<pair<int, int>> chain {};
        for (auto& v : pairs) {
            chain.emplace_back(v[1], v[0]);
        }
        sort(chain.begin(), chain.end());
        int result = 0;
        int border = -1001;
        for (auto& pair : chain) {
            if (pair.second > border) {
                result++;
                border = pair.first;
            }
        }
        return result;
    }
};
// @lc code=end
