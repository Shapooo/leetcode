#include <algorithm>
#include <cstdlib>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1054 lang=cpp
 *
 * [1054] 距离相等的条形码
 */

// @lc code=start
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes)
    {
        unordered_map<int, int> m {};
        for (const auto& n : barcodes) {
            m[n]++;
        }
        vector<pair<int, int>> v {};
        for (auto& p : m) {
            v.emplace_back(p.second, p.first);
        }
        make_heap(v.begin(), v.end());
        vector<int> res {};
        while (!v.empty()) {
            if (res.back() != v[0].second) {
                res.emplace_back(v[0].second);
                v[0].first--;
                pop_heap(v.begin(), v.end());
                if (v.back().first == 0) {
                    v.pop_back();
                } else {
                    push_heap(v.begin(), v.end());
                }
            } else {
                pop_heap(v.begin(), v.end());
                res.emplace_back(v[0].second);
                v[0].first--;
                pop_heap(v.begin(), v.end() - 1);
                if (v[v.size() - 2].first == 0) {
                    v[v.size() - 2] = v.back();
                    v.pop_back();
                    push_heap(v.begin(), v.end());
                } else {
                    push_heap(v.begin(), v.end() - 1);
                    push_heap(v.begin(), v.end());
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> barcodes { 7, 7, 7, 8, 5, 7, 5, 5, 5, 8 };
    sol.rearrangeBarcodes(barcodes);
}
