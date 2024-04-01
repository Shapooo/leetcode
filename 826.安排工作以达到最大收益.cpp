#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=826 lang=cpp
 *
 * [826] 安排工作以达到最大收益
 */

// @lc code=start
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        int n = difficulty.size(), m = worker.size();
        vector<int> work_idx(n);
        for (int i = 0; i < n; ++i) {
            work_idx[i] = i;
        }
        sort(work_idx.begin(), work_idx.end(), [&](int lhs, int rhs) {
            if (difficulty[lhs] == difficulty[rhs]) {
                return profit[lhs] > profit[rhs];
            }
            return difficulty[lhs] < difficulty[rhs];
        });
        int l {};
        for (int i = 1; i < n; ++i) {
            if (profit[work_idx[i]] > profit[work_idx[l]]) {
                work_idx[++l] = work_idx[i];
            }
        }
        work_idx.erase(work_idx.begin() + l + 1, work_idx.end());
        int res {};
        for (auto& w : worker) {
            int l = 0, r = work_idx.size() - 1;
            if (difficulty[work_idx[l]] > w) {
                continue;
            }
            while (l <= r) {
                int mid = (l + r) / 2;
                if (difficulty[work_idx[mid]] == w) {
                    r = mid;
                    break;
                } else if (difficulty[work_idx[mid]] > w) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            res += profit[work_idx[r]];
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> difficulty, profit, worker;
    // difficulty = { 2, 4, 6, 8, 10 };
    // profit = { 10, 20, 30, 40, 50 };
    // worker = { 4, 5, 6, 7 };
    // printf("%d \n", sol.maxProfitAssignment(difficulty, profit, worker));
    // difficulty = { 85, 47, 57 };
    // profit = { 24, 66, 99 };
    // worker = { 40, 25, 25 };
    // printf("%d \n", sol.maxProfitAssignment(difficulty, profit, worker));
    difficulty = { 27, 28, 31, 44, 44 };
    profit = { 29, 39, 60, 84, 93 };
    worker = { 67, 53, 61, 56, 63 };
    printf("%d \n", sol.maxProfitAssignment(difficulty, profit, worker));
}