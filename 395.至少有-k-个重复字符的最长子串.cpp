#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

// @lc code=start
class Solution {
    int helper(string& s, int start, int end, int k)
    {
        if (end - start < k) {
            return 0;
        }
        vector<int> cnt_vec(26);
        unordered_set<char> set {};
        for (int i = start; i < end; i++) {
            cnt_vec[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt_vec[i] > 0 && cnt_vec[i] < k) {
                set.insert(i + 'a');
            }
        }
        if (!set.size()) {
            return end - start;
        }
        int last = 0;
        int res = 0;
        for (int i = 0; i < end; ++i) {
            if (set.find(s[i]) != set.end()) {
                res = max(res, helper(s, last, i, k));
                last = i + 1;
            }
        }
        res = max(res, helper(s, last, end, k));
        return res;
    }

public:
    int longestSubstring(string s, int k)
    {
        int n = s.size();
        return helper(s, 0, n, k);
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    string s = "aaabb";
    int k = 3;
    sol.longestSubstring(s, k);
}