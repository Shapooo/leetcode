#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1410 lang=cpp
 *
 * [1410] HTML 实体解析器
 */

// @lc code=start
class Solution {
    int helper(string s)
    {
        printf("%s\n", s.c_str());
        if (s.starts_with("quot;"))
            return 0;
        if (s.starts_with("apos;"))
            return 1;
        if (s.starts_with("amp;"))
            return 2;
        if (s.starts_with("gt;"))
            return 3;
        if (s.starts_with("lt;"))
            return 4;
        if (s.starts_with("frasl;"))
            return 5;

        return -1;
    }

public:
    string entityParser(string text)
    {
        string idx[6] = { "&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;" };
        string res {};
        int n = text.size();
        for (int i = 0; i < n;) {
            if (text[i] == '&') {
                auto m = helper(text.substr(i + 1, 6));
                switch (m) {
                case 0: {
                    res.push_back('"');
                    i += 6;
                    break;
                }
                case 1: {
                    res.push_back('\'');
                    i += 6;
                    break;
                }
                case 2: {
                    res.push_back('&');
                    i += 5;
                    break;
                }
                case 3: {
                    res.push_back('>');
                    i += 4;
                    break;
                }
                case 4: {
                    res.push_back('<');
                    i += 4;
                    break;
                }
                case 5: {
                    res.push_back('/');
                    i += 7;
                    break;
                }
                default: {
                    res.push_back(text[i]);
                    ++i;
                    break;
                }
                }
            } else {
                res.push_back(text[i]);
                ++i;
            }
        }
        return res;
    }
};
// @lc code=end
