#include <bitset>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1947 lang=cpp
 *
 * [1947] 最大兼容性评分和
 */

// @lc code=start
class Solution {
    int m, n;
    bitset<8> arranged {};
    int evaluate(vector<int>& student, vector<int>& mentor)
    {
        int res {};
        for (int i = 0; i < n; ++i) {
            res += student[i] == mentor[i];
        }
        return res;
    }
    int bt(int matchability[8][8], int student_id)
    {
        if (student_id == m) {
            return 0;
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            if (!arranged[i]) {
                arranged[i] = 1;
                int tmp = bt(matchability, student_id + 1) + matchability[student_id][i];
                res = max(res, tmp);
                arranged[i] = 0;
            }
        }
        return res;
    }

public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors)
    {
        int matchability[8][8] {};
        m = students.size(), n = students[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                matchability[i][j] = evaluate(students[i], mentors[j]);
            }
        }
        int res = bt(matchability, 0);
        return res;
    }
};
// @lc code=end
