#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2575 lang=cpp
 *
 * [2575] 找出字符串的可整除数组
 */

// @lc code=start
class Solution {
public:
    vector<int> divisibilityArray(string word, int m)
    {
        int n = word.size();
        unsigned long long rem = 0;
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            rem = (rem * 10 + word[i] - '0') % m;
            res[i] = !rem;
        }
        return res;
    }
};
// @lc code=end
