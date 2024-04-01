#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
    {
        auto len = bookings.size();
        vector<pair<int, int>> first_seats(len), last_seats(len);
        for (size_t i = 0; i < len; i++) {
            first_seats[i] = { bookings[i][0], bookings[i][2] };
            last_seats[i] = { bookings[i][1], bookings[i][2] };
        }
        sort(first_seats.begin(), first_seats.end());
        sort(last_seats.begin(), last_seats.end());

        int cum {}, fs_index {}, ls_index {};
        vector<int> res(n);
        for (size_t i = 0; i < n; i++) {
            while (fs_index < len && first_seats[fs_index].first <= i + 1) {
                cum += first_seats[fs_index].second;
                fs_index++;
            }
            while (ls_index < len && last_seats[ls_index].first < i + 1) {
                cum -= last_seats[ls_index].second;
                ls_index++;
            }
            res[i] = cum;
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution sol;
    vector<vector<int>> bookings = { { 1, 2, 10 }, { 2, 3, 20 }, { 2, 5, 25 } };
    int n = 5;
    for (auto&& i : sol.corpFlightBookings(bookings, n)) {
        cout << i << ' ';
    }
    cout << endl;

    bookings = { { 1, 2, 10 }, { 2, 2, 15 } }, n = 2;
    for (auto&& i : sol.corpFlightBookings(bookings, n)) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
