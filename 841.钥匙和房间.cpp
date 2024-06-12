#include <bitset>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        bitset<1000> visited {};
        dfs(rooms, visited, 0);
        int size = rooms.size();
        for (int i = 0; i < size; ++i) {
            if (visited[i] == 0) {
                return false;
            }
        }
        return true;
    }
    void dfs(vector<vector<int>>& rooms, bitset<1000>& visited, int room)
    {
        if (visited[room]) {
            return;
        }
        visited[room] = 1;
        for (auto& i : rooms[room]) {
            dfs(rooms, visited, i);
        }
    }
};
// @lc code=end
