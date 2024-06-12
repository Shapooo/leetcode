#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int size = temperatures.size();
        vector<int> result(size, 0);
        for (int i = size - 2; i >= 0; --i) {
            int pos = i + 1, val = 0;
            while (true) {
                if (temperatures[i] < temperatures[pos]) {
                    val = pos - i;
                    break;
                } else if (result[pos]) {
                    pos += result[pos];
                } else {
                    break;
                }
            }
            result[i] = val;
        }
        return result;
    }
};
// @lc code=end
