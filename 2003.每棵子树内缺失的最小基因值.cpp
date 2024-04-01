#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2003 lang=cpp
 *
 * [2003] 每棵子树内缺失的最小基因值
 */

// @lc code=start
class Solution {
    void dfs(vector<vector<int>>& children, vector<int>& nums, bitset<100001>& visited, int n)
    {
        if (visited[nums[n]])
            return;
        visited[nums[n]] = true;
        for (auto& c : children[n]) {
            dfs(children, nums, visited, c);
        }
    }

public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums)
    {
        int n = parents.size();
        vector<vector<int>> children(parents.size());
        for (int i = 1; i < n; i++) {
            children[parents[i]].push_back(i);
        }
        vector<int> ans(n, 1);
        bitset<100001> visited;
        int cur = -1, old = 2;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                cur = i;
                break;
            }
        }
        while (cur != -1) {
            dfs(children, nums, visited, cur);
            for (; old <= 100001; old++) {
                if (!visited[old]) {
                    ans[cur] = old;
                    break;
                }
            }
            cur = parents[cur];
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> parents = { -1, 0, 0, 2 }, nums = { 1, 2, 3, 4 };
    sol.smallestMissingValueSubtree(parents, nums);
    return 0;
}