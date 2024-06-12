#include <climits>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int size = gas.size();
        int start = 0;
        int remain = 0;
        int min = INT_MAX;
        for (int i = 0; i < size; ++i) {
            remain += gas[i] - cost[i];
            if (remain < min) {
                min = remain;
                start = i + 1;
            }
        }
        if (remain < 0)
            return -1;
        if (min >= 0)
            return 0;
        return start;
    }
};
// @lc code=end
