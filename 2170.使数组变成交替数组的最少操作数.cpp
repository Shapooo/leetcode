#include <cstdio>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2170 lang=cpp
 *
 * [2170] 使数组变成交替数组的最少操作数
 */

// @lc code=start
class Solution {
    vector<int> help(unordered_map<int, int>& cnt_map)
    {
        auto cmp = [](pair<int, int> lhs, pair<int, int> rhs) { return lhs.second > rhs.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
        for (auto& p : cnt_map) {
            if (que.size() < 2) {
                que.push(p);
            } else if (p.second > que.top().second) {
                que.pop();
                que.push(p);
            }
        }
        if (que.size() == 2) {
            vector<int> res(4);
            auto a = que.top();
            res[2] = a.first;
            res[3] = a.second;
            que.pop();
            a = que.top();
            res[0] = a.first;
            res[1] = a.second;
            return res;
        } else {
            vector<int> res(2);
            auto a = que.top();
            res[0] = a.first;
            res[1] = a.second;
            return res;
        }
    }

public:
    int minimumOperations(vector<int>& nums)
    {
        unordered_map<int, int> even {}, odd {};
        int len = nums.size();
        if (len < 2) {
            return 0;
        }
        for (int i = 0; i < len; ++i) {
            if (i % 2) {
                odd[nums[i]]++;
            } else {
                even[nums[i]]++;
            }
        }
        auto a = help(even);
        auto b = help(odd);
        if (a[0] == b[0]) {
            if (a.size() == 4 && b.size() == 4) {
                return min(len - a[1] - b[3], len - a[3] - b[1]);
            } else if (a.size() == 2 && b.size() == 2) {
                return len / 2;
            } else if (a.size() == 2) {
                return len - a[1] - b[3];
            } else {
                return len - a[3] - b[1];
            }
        } else {
            return len - a[1] - b[1];
        }
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> nums { 1, 2, 2, 2, 2 };
    sol.minimumOperations(nums);
    nums = { 69, 91, 47, 74, 75, 94, 22, 100, 43, 50, 82, 47, 40, 51, 90, 27, 98, 85, 47, 14, 55, 82, 52, 9, 65, 90, 86, 45, 52, 52, 95, 40, 85, 3, 46, 77, 16, 59, 32, 22, 41, 87, 89, 78, 59, 78, 34, 26, 71, 9, 82, 68, 80, 74, 100, 6, 10, 53, 84, 80, 7, 87, 3, 82, 26, 26, 14, 37, 26, 58, 96, 73, 41, 2, 79, 43, 56, 74, 30, 71, 6, 100, 72, 93, 83, 40, 28, 79, 24 };
    printf("%lu\n", nums.size());
    printf("%d\n", sol.minimumOperations(nums));
}