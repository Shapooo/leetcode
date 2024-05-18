#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2244 lang=cpp
 *
 * [2244] 完成所有任务需要的最少轮数
 */

// @lc code=start
class Solution {
public:
    int minimumRounds(vector<int>& tasks)
    {
        int res {};
        unordered_map<int, int> m {};
        for (auto const& t : tasks) {
            m[t]++;
        }
        for (auto const p : m) {
            if (p.second == 1) {
                return -1;
            }
            res += (p.second + 2) / 3;
        }
        return res;
    }
};
// @lc code=end
