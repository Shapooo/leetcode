#include <cstdio>
#include <deque>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit)
    {
        deque<pair<int, int>> inc_que {}, dec_que {};
        inc_que.emplace_back(nums[0], 0);
        dec_que.emplace_back(nums[0], 0);
        int res = 1;
        int l = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            while (!dec_que.empty() && nums[i] > dec_que.back().first) {
                dec_que.pop_back();
            }
            dec_que.emplace_back(nums[i], i);
            while (!inc_que.empty() && nums[i] < inc_que.back().first) {
                inc_que.pop_back();
            }
            inc_que.emplace_back(nums[i], i);
            while (dec_que.front().first - inc_que.front().first > limit) {
                if (dec_que.front().second > inc_que.front().second) {
                    l = inc_que.front().second + 1;
                    inc_que.pop_front();
                } else if (dec_que.front().second < inc_que.front().second) {
                    l = dec_que.front().second + 1;
                    dec_que.pop_front();
                } else {
                    l = dec_que.front().second + 1;
                    dec_que.pop_front();
                    inc_que.pop_front();
                }
            }
            res = max(res, i - l + 1);
            // printf("inc: ");
            // for (auto& n : inc_que) {
            //     printf("(%d,%d) ", n.first, n.second);
            // }
            // printf("\n");
            // printf("dec: ");
            // for (auto& n : dec_que) {
            //     printf("(%d,%d) ", n.first, n.second);
            // }
            // printf("\n");
            // printf("res: %d\n", res);
        }
        return res;
    }
};
// @lc code=end

int main()
{
    int limit = 10;
    Solution sol {};
    vector<int> nums { 4, 10, 2, 6, 1 };
    printf("%d\n", sol.longestSubarray(nums, limit));
}