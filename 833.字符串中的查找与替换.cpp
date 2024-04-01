#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=833 lang=cpp
 *
 * [833] 字符串中的查找与替换
 */

// @lc code=start
class Solution {
    int comp(string& a, int start, string& b)
    {
        if (a.size() - start < b.size()) {
            return -1;
        }
        for (int i = 0; i < b.size(); i++) {
            if (b[i] != a[i + start]) {
                return -1;
            }
        }
        return 0;
    }

public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets)
    {
        int len = indices.size();
        vector<int> idx(len, 0);
        string res {};
        for (int i = 0; i < len; ++i) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&indices](int l, int r) { return indices[l] < indices[r]; });
        res.append(s.substr(0, indices[idx[0]]));
        for (int i = 0; i < len; ++i) {
            if (i < len - 1) {
                if (comp(s, indices[idx[i]], sources[idx[i]])) {
                    res.append(s.substr(indices[idx[i]], indices[idx[i + 1]] - indices[idx[i]]));
                } else {
                    res.append(targets[idx[i]]);
                    res.append(s.substr(indices[idx[i]] + sources[idx[i]].size(), indices[idx[i + 1]] - indices[idx[i]] - sources[idx[i]].size()));
                }
            } else {
                if (comp(s, indices[idx[i]], sources[idx[i]])) {
                    res.append(s.substr(indices[idx[i]]));
                } else {
                    res.append(targets[idx[i]]);
                    res.append(s.substr(indices[idx[i]] + sources[idx[i]].size()));
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
    string s { "jjievdtjfb" };
    vector<int> indices { 4, 6, 1 };
    vector<string> sources { "md", "tjgb", "jf" };
    vector<string> targets { "foe", "oov", "e" };
    cout << sol.findReplaceString(s, indices, sources, targets);
    return 0;
}
