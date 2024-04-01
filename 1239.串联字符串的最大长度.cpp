#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 *
 * [1239] 串联字符串的最大长度
 */

// @lc code=start
class Solution {
    int n;
    int dfs(vector<pair<int, u_int32_t>>& smap, int start, u_int32_t cur_status, int len)
    {
        if (start >= n) {
            return len;
        }
        int res = len;
        for (int i = start; i < n; ++i) {
            if ((cur_status & smap[i].second) == 0) {
                res = max(res, dfs(smap, i + 1, cur_status | smap[i].second, len + smap[i].first));
            }
        }
        return res;
    }

public:
    int maxLength(vector<string>& arr)
    {
        vector<pair<int, u_int32_t>> smap {};
        for (auto& s : arr) {
            bool flag = true;
            u_int32_t bits {};
            for (auto& c : s) {
                int bit = 1 << (c - 'a');
                if (bit & bits) {
                    flag = false;
                    break;
                } else {
                    bits |= bit;
                }
            }
            if (flag) {
                smap.emplace_back(s.size(), bits);
            }
        }
        n = smap.size();
        return dfs(smap, 0, 0, 0);
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<string> arr { "aa", "bb" };
    sol.maxLength(arr);
}