#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2594 lang=cpp
 *
 * [2594] 修车的最少时间
 */

// @lc code=start
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars)
    {
        int n = ranks.size();
        int rank_map[101][2] {};

        for (auto& r : ranks) {
            rank_map[r][0]++;
        }

        vector<int> rank_heap {};
        for (int i = 1; i <= 100; ++i) {
            if (rank_map[i][0]) {
                rank_heap.push_back(i);
            }
        }
        auto cmp = [&](auto lhs, auto rhs) {
            return (long long)lhs * (rank_map[lhs][1] + 1) * (rank_map[lhs][1] + 1) > (long long)rhs * (rank_map[rhs][1] + 1) * (rank_map[rhs][1] + 1);
        };
        make_heap(rank_heap.begin(), rank_heap.end(), cmp);
        long long res = 0;
        while (cars > 0) {
            pop_heap(rank_heap.begin(), rank_heap.end(), cmp);
            auto& mach = rank_heap.back();
            rank_map[mach][1]++;
            cars -= rank_map[mach][0];
            res = max(res, (long long)mach * rank_map[mach][1] * rank_map[mach][1]);
            // printf("%d * %d ^ 2 = %lld, res =  %lld, rem cars = %d \n", mach, rank_map[mach][1], (long long)mach * rank_map[mach][1] * rank_map[mach][1], res, cars);
            push_heap(rank_heap.begin(), rank_heap.end(), cmp);
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> ranks { 4, 2, 3, 1 };
    int cars { 10 };
    sol.repairCars(ranks, cars);
}