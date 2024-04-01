#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
typedef long long ll;
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        ll res = 0;
        ll x {}, y {};
        int dir {};
        int delta[][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        unordered_map<int, vector<int>> rows {}, cols {};
        for (auto& cord : obstacles) {
            rows[cord[1]].push_back(cord[0]);
            cols[cord[0]].push_back(cord[1]);
        }
        for (auto& row : rows) {
            sort(row.second.begin(), row.second.end());
        }
        for (auto& col : cols) {
            sort(col.second.begin(), col.second.end());
        }
        for (auto& cmd : commands) {
            if (cmd > 0) {
                if (dir == 0) {
                    int e = y + cmd;
                    auto col = cols.find(x);
                    if (col != cols.end()) {
                        auto a = upper_bound(col->second.begin(), col->second.end(), y);
                        if (a != col->second.end() && *a <= e) {
                            e = *a - 1;
                        }
                    }
                    y = e;
                } else if (dir == 1) {
                    int e = x + cmd;
                    auto row = rows.find(y);
                    if (row != cols.end()) {
                        auto a = upper_bound(row->second.begin(), row->second.end(), x);
                        if (a != row->second.end() && *a <= e) {
                            e = *a - 1;
                        }
                    }
                    x = e;
                } else if (dir == 2) {
                    int e = y - cmd;
                    auto col = cols.find(x);
                    if (col != cols.end()) {
                        auto a = upper_bound(col->second.rbegin(), col->second.rend(), y, [](const int& l, const int& r) { return l > r; });
                        if (a != col->second.rend() && *a >= e) {
                            e = *a + 1;
                        }
                    }
                    y = e;
                } else {
                    int e = x - cmd;
                    auto row = rows.find(y);
                    if (row != rows.end()) {
                        auto a = upper_bound(row->second.rbegin(), row->second.rend(), x, [](const int& l, const int& r) { return l > r; });
                        if (a != row->second.rend() && *a >= e) {
                            e = *a + 1;
                        }
                    }
                    x = e;
                }
            } else {
                dir = (dir + 4 + (cmd == -1 ? 1 : -1)) % 4;
            }
            cout << x << ' ' << y << ' ' << dir << endl;
            res = max(res, x * x + y * y);
        }

        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution sol {};
    vector<int> commands = { 7, -2, -2, 7, 5 };
    vector<vector<int>> obstacles = { { -3, 2 }, { -2, 1 }, { 0, 1 }, { -2, 4 }, { -1, 0 }, { -2, -3 }, { 0, -3 }, { 4, 4 }, { -3, 3 }, { 2, 2 } };
    cout << sol.robotSim(commands, obstacles) << endl;
    commands = { -2, 3, -1, -2, 4 };
    obstacles = { { -2, 2 }, { 4, -3 }, { 2, 3 }, { -3, -2 }, { -2, -4 }, { 0, -4 }, { 2, 2 }, { 3, -2 }, { 2, -5 }, { 2, 1 } };
    cout << sol.robotSim(commands, obstacles) << endl;

    return 0;
}
