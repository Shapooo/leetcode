#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=630 lang=cpp
 *
 * [630] 课程表 III
 */

// @lc code=start
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses)
    {
        sort(courses.begin(), courses.end(), [](const auto& lhs, const auto& rhs) {
            return lhs[1] < rhs[1];
        });
        priority_queue<int> que {};
        int acc_time {};
        for (const auto& c : courses) {
            if (acc_time + c[0] <= c[1]) {
                que.push(c[0]);
                acc_time += c[0];
            } else if (!que.empty() && que.top() > c[0]) {
                acc_time -= que.top() - c[0];
                que.pop();
                que.push(c[0]);
            }
        }
        return que.size();
    }
};
// @lc code=end
