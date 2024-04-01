#include <algorithm>
#include <cstdio>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2512 lang=cpp
 *
 * [2512] 奖励最顶尖的 K 名学生
 */

// @lc code=start
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k)
    {
        unordered_set<string> pos_set {}, neg_set {};
        for (auto& po : positive_feedback) {
            pos_set.insert(std::move(po));
        }
        for (auto& ne : negative_feedback) {
            neg_set.insert(std::move(ne));
        }
        int n = student_id.size();
        vector<pair<int, int>> scores(n);
        for (int i = 0; i < n; ++i) {
            int idx = 0;
            int len = report[i].size();
            int score = 0;
            while (idx < len) {
                string a {};
                while (idx < len && report[i][idx] != ' ') {
                    a.push_back(report[i][idx]);
                    idx++;
                }
                idx++;
                auto it = pos_set.find(a);
                if (it != pos_set.end()) {
                    score += 3;
                } else if (neg_set.find(a) != neg_set.end()) {
                    score -= 1;
                }
            }
            scores[i] = { score, student_id[i] };
        }
        sort(scores.begin(), scores.end(), [&](auto& lhs, auto& rhs) {
            if (lhs.first == rhs.first) {
                return lhs.second < rhs.second;
            }
            return lhs.first > rhs.first;
        });
        vector<int> res(k);
        for (int i = 0; i < k; ++i) {
            res[i] = scores[i].second;
        }
        return res;
    }
};
// @lc code=end
