#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1023 lang=cpp
 *
 * [1023] 驼峰式匹配
 */

// @lc code=start
class Solution {
    bool isMatch(string& query, string& pattern)
    {
        size_t iq {}, ip {};
        auto len1 { query.size() }, len2 { pattern.size() };
        if (len1 < len2) {
            return false;
        }
        while (iq < len1 && ip < len2) {
            if (query[iq] == pattern[ip]) {
                iq++, ip++;
            } else if (query[iq] < 'a') {
                return false;
            } else {
                iq++;
            }
        }
        if (ip < len2) {
            return false;
        }
        while (iq < len1) {
            if (query[iq] < 'a') {
                return false;
            }
            iq++;
        }
        return true;
    }

public:
    vector<bool> camelMatch(vector<string>& queries, string pattern)
    {
        auto len = queries.size();
        vector<bool> res(len);
        for (size_t i = 0; i < len; i++) {
            res[i] = isMatch(queries[i], pattern);
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution sol;
    vector<string> queries = { "FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack" };
    string pattern = "FB";
    for (auto&& i : sol.camelMatch(queries, pattern)) {
        cout << i << ' ';
    }
    cout << endl;

    pattern = "FoBa";
    for (auto&& i : sol.camelMatch(queries, pattern)) {
        cout << i << ' ';
    }
    cout << endl;
    pattern = "FoBaT";
    for (auto&& i : sol.camelMatch(queries, pattern)) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
