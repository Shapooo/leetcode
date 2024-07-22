#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=3112 lang=cpp
 *
 * [3112] 访问消失节点的最少时间
 */

// @lc code=start
class Solution {
public:
  vector<int> minimumTime(int n, vector<vector<int>> &edges,
                          vector<int> &disappear) {
    vector<unordered_map<int, int>> nei_tab(n);
    for (auto const &edge : edges) {
      auto it = nei_tab[edge[0]].find(edge[1]);
      if (it == nei_tab[edge[0]].end()) {
        nei_tab[edge[0]][edge[1]] = edge[2];
        nei_tab[edge[1]][edge[0]] = edge[2];
      } else if (it->second > edge[2]) {
        it->second = edge[2];
        nei_tab[edge[1]][edge[0]] = edge[2];
      }
    }
    vector<int> visited(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   std::greater<pair<int, int>>>
        pq{};
    pq.emplace(0, 0);
    vector<int> res(n, -1);
    while (!pq.empty()) {
      auto a = pq.top();
      int time = a.first;
      int idx = a.second;
      pq.pop();
      if (visited[idx]) {
        continue;
      }
      visited[idx] = 1;
      res[idx] = time;
      for (auto const &nei : nei_tab[idx]) {
        int vtime = nei.second + time;
        if (!visited[nei.first] && vtime < disappear[nei.first]) {
          pq.emplace(vtime, nei.first);
        }
      }
    }

    return res;
  }
};
// @lc code=end
