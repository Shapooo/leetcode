#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2359 lang=cpp
 *
 * [2359] 找到离给定两个节点最近的节点
 */

// @lc code=start
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2)
    {
        bool cyclical = true;
        for (auto& n : edges) {
            if (n == -1) {
                cyclical = false;
                break;
            }
        }
    }
};
// @lc code=end
