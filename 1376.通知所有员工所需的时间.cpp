#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1376 lang=cpp
 *
 * [1376] 通知所有员工所需的时间
 */

// @lc code=start
class Solution {
    int mem[100'001] {};
    int find(vector<int>& M, vector<int>& I, int id)
    {
        if (M[id] == -1) {
            return 0;
        }
        if (mem[id]) {
            return mem[id];
        }
        return mem[id] = find(M, I, M[id]) + I[M[id]];
    }

public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        int res {};
        for (size_t i = 0; i < n; i++) {
            res = max(res, find(manager, informTime, i));
        }
        return res;
    }
};
// @lc code=end
