#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1870 lang=cpp
 *
 * [1870] 准时到达的列车最小时速
 */

// @lc code=start
class Solution {
    double calc_time(vector<int>& dist, int speed)
    {
        long long res {};
        int n = dist.size();
        for (int i = 0; i < n - 1; ++i) {
            res += (dist[i] + speed - 1) / speed;
        }
        return (double)res + (double)dist[n - 1] / speed;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        int n = dist.size();
        if (hour - n + 1 <= 0) {
            return -1;
        }
        int right = 0;
        long long sum = 0;
        for (auto& d : dist) {
            sum += d;
            right = max(right, d);
        }
        right *= 100;
        int left = sum / (long long)(hour + 0.99);
        if (!left) {
            return 1;
        }
        while (left < right) {
            int mid = (left + right) / 2;
            double time = calc_time(dist, mid);
            printf("%d %d %d %lf\n", left, right, mid, time);
            if (time == hour) {
                return mid;
            }
            if (time > hour) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> dist { 1, 3, 2 };
    double hour = 6;
    // printf("%d\n", sol.minSpeedOnTime(dist, hour));
    // hour = 2.7;
    // printf("%d\n", sol.minSpeedOnTime(dist, hour));
    // hour = 1.9;
    // printf("%d\n", sol.minSpeedOnTime(dist, hour));
    // dist = { 1, 1, 100000 };
    // hour = 2.01;
    // printf("%d\n", sol.minSpeedOnTime(dist, hour));
    // dist = { 2, 1, 5, 4, 4, 3, 2, 9, 2, 10 };
    // hour = 75.12;
    // printf("%d\n", sol.minSpeedOnTime(dist, hour));
    dist = { 69 };
    hour = 4.6;
    printf("%d\n", sol.minSpeedOnTime(dist, hour));
}