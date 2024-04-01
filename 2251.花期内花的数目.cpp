#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2251 lang=cpp
 *
 * [2251] 花期内花的数目
 */

// @lc code=start
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people)
    {
        vector<int> start {}, end {};
        for (auto& f : flowers) {
            start.emplace_back(f[0]);
            end.emplace_back(f[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int n = people.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            int blsmed = upper_bound(start.begin(), start.end(), people[i]) - start.begin();
            int faded = lower_bound(end.begin(), end.end(), people[i]) - end.begin();
            res[i] = blsmed - faded;
        }
        return res;
    }
};
// @lc code=end
