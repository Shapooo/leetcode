#include <cstdio>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1488 lang=cpp
 *
 * [1488] 避免洪水泛滥
 */

// @lc code=start
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains)
    {
        unordered_map<int, int> full {};
        int n = rains.size();
        vector<int> res(n, 1);
        set<int> rainless {};
        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                rainless.insert(i);
                continue;
            }
            auto it = full.find(rains[i]);
            if (it != full.end()) {
                auto earliest_it = rainless.upper_bound(it->second);
                if (earliest_it == rainless.end()) {
                    return {};
                }
                res[*earliest_it] = rains[i];
                rainless.erase(earliest_it);
            }
            full[rains[i]] = i;
            res[i] = -1;
        }

        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> rains = { 1, 2, 0, 0, 2, 1 };
    for (auto n : sol.avoidFlood(rains)) {
        printf("%d ", n);
    }
    printf("\n");
}