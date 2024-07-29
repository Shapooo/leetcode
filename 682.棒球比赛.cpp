#include <algorithm>
#include <cstdio>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution {
  public:
    int calPoints(vector<string> &operations) {
        vector<int> record{};
        for (auto const &op : operations) {
            if (op == "+") {
                record.push_back(*(record.end() - 1) + *(record.end() - 2));
            } else if (op == "D") {
                record.push_back(*(record.end() - 1) * 2);
            } else if (op == "C") {
                record.pop_back();
            } else {
                auto a = stoi(op);
                record.push_back(a);
            }
        }
        for (auto const &a : record) {
            printf("%d ", a);
        }
        return accumulate(record.begin(), record.end(), 0);
    }
};
// @lc code=end

int main() {
    Solution sol{};
    vector<string> operations{"5", "2", "C", "D", "+"};
    sol.calPoints(operations);
}