#include <algorithm>
#include <bitset>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1311 lang=cpp
 *
 * [1311] 获取你好友已观看的视频
 */

// @lc code=start
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level)
    {
        unordered_map<string, int> videos {};
        bitset<100> ids {};
        queue<pair<int, int>> que {};
        que.push({ id, 0 });
        ids[id] = 1;
        while (!que.empty()) {
            auto p = que.front();
            que.pop();
            if (p.second == level) {
                for (auto& v : watchedVideos[p.first]) {
                    videos[v]++;
                }
            } else {
                for (auto fid : friends[p.first]) {
                    if (!ids[fid]) {
                        que.emplace(fid, p.second + 1);
                        ids[fid] = 1;
                    }
                }
            }
        }

        vector<string> res {};
        for (auto& p : videos) {
            res.push_back(p.first);
        }
        sort(res.begin(), res.end(), [&videos](string& lhs, string& rhs) {
            if (videos[lhs] == videos[rhs]) {
                return lhs < rhs;
            } else {
                return videos[lhs] < videos[rhs];
            }
        });
        return res;
    }
};
// @lc code=end
