#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
    bool _helper(unordered_map<string, map<string, int>>& map, int aim_size)
    {
        if (_result.size() == aim_size) {
            return true;
        }
        auto it = map.find(_result.back());
        if (it != map.end()) {
            for (auto& i : it->second) {
                if (!i.second)
                    continue;
                i.second--;
                const string& dest = i.first;
                _result.push_back(dest);
                if (_helper(map, aim_size)) {
                    return true;
                }
                _result.pop_back();
                i.second++;
            }
        }
        return false;
    }
    vector<string> _result { "JFK" };

public:
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        unordered_map<string, map<string, int>> map {};
        for (auto& i : tickets) {
            map[i[0]][i[1]]++;
        }
        _helper(map, tickets.size() + 1);
        return _result;
    }
};
// @lc code=end
