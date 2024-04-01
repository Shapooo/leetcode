#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
class Solution {
    int euclideanDistance(vector<int>& p1, vector<int>& p2)
    {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }

public:
    int numberOfBoomerangs(vector<vector<int>>& points)
    {
        unordered_map<int, int> map;
        int n = points.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                auto dis = euclideanDistance(points[i], points[j]);
                map[dis]++;
            }
        }
        int res = 0;
        for (auto& [_, v] : map) {
            res += v * (v - 1);
            printf("%d %d\n", v, res);
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<vector<int>> points = { { 0, 0 }, { 1, 0 }, { 2, 0 } };
    points = { { 0, 0 }, { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    sol.numberOfBoomerangs(points);

    return 0;
}