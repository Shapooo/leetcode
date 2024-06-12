#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1598 lang=cpp
 *
 * [1598] 文件夹操作日志搜集器
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<string>& logs)
    {
        int result = 0;
        for (auto& s : logs) {
            if (s == "../") {
                result = result ? result - 1 : 0;
            } else if (s != "./") {
                result++;
            }
        }
        return result;
    }
};
// @lc code=end
