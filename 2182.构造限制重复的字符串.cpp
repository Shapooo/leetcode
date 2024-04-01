#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=2182 lang=cpp
 *
 * [2182] 构造限制重复的字符串
 */

// @lc code=start
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        int cmap[26] {};
        for (auto c : s) {
            cmap[c - 'a']++;
        }
        int repcnt = 0;
        int len = s.size();
        string res {};
        int last { 25 }, subseq { 26 };
        while (last >= 0) {
            while (last >= 0 && !cmap[last]) {
                last--;
            }
            if (last < 0) {
                break;
            }
            if (res.empty() || last != res.back() - 'a') {
                repcnt = 0;
            }
            while (repcnt < repeatLimit && cmap[last]) {
                cmap[last]--;
                res.push_back(last + 'a');
                repcnt++;
            }
            if (repcnt == repeatLimit) {
                subseq = last - 1;
                while (subseq >= 0 && !cmap[subseq]) {
                    subseq--;
                }
                if (subseq < 0) {
                    break;
                }
                res.push_back(subseq + 'a');
                repcnt = 1;
                cmap[subseq]--;
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    string s = "cczazcc";
    int repeatLimit = 3;
    printf("%s", sol.repeatLimitedString(s, repeatLimit).c_str());
}