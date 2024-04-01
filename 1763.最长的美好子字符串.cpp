#include <cstring>
#include <memory>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1763 lang=cpp
 *
 * [1763] 最长的美好子字符串
 */

// @lc code=start
class Solution {
public:
    string longestNiceSubstring(string s)
    {
        int mem[26][2] {};
        int len = s.size();
        int ma = 0;
        string res {};
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                if (isupper(s[j])) {
                    mem[s[j] - 'A'][1]++;
                } else {
                    mem[s[j] - 'a'][0]++;
                }
                bool fulfil = true;
                for (int k = 0; k < 26; ++k) {
                    if (!mem[k][0] && !mem[k][1] || mem[k][0] && mem[k][1]) {
                        continue;
                    } else {
                        fulfil = false;
                        break;
                    }
                }
                if (fulfil && j - i + 1 > ma) {
                    ma = j - i + 1;
                    res = s.substr(i, ma);
                }
            }
            memset(mem, 0, sizeof(mem));
        }
        return res;
    }
};
// @lc code=end
