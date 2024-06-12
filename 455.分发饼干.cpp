#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gsize = g.size();
        int ssize = s.size();
        for (int i = 0, j = 0; i < gsize; ++i) {
            while (j < ssize && s[j] < g[i])
                j++;
            if (j >= ssize)
                return i;
            j++;
        }
        return gsize;
    }
};
// @lc code=end
