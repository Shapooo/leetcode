#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=722 lang=cpp
 *
 * [722] 删除注释
 */

// @lc code=start
class Solution {
    bool strip_preceding_block(string& s)
    {
        auto block_end = s.find("*/");
        if (string::npos == block_end) {
            return true;
        }
        s = s.substr(block_end + 2);
        return false;
    }
    bool strip_comment(string& s)
    {
        size_t line_comment_pos = s.find("//");
        size_t block_comment_pos = s.find("/*");
        if (string::npos == line_comment_pos && string::npos == block_comment_pos) {
            return false;
        }
        if (string::npos == block_comment_pos) {
            s = s.substr(0, line_comment_pos);
            return false;
        } else if (string::npos == line_comment_pos || line_comment_pos > block_comment_pos) {
            auto block_end_pos = s.find("*/", block_comment_pos + 2);
            if (block_end_pos == string::npos) {
                s = s.substr(0, block_comment_pos);
                return true;
            } else {
                string tmp = s.substr(block_end_pos + 2);
                auto res = strip_comment(tmp);
                s = s.substr(0, block_comment_pos) + tmp;
                return res;
            }
        } else {
            s = s.substr(0, line_comment_pos);
            return false;
        }
    }

public:
    vector<string> removeComments(vector<string>& source)
    {
        vector<string> res {};
        bool in_comment = false;
        for (auto& s : source) {
            if (in_comment && strip_preceding_block(s)) {
                continue;
            }
            bool ic = strip_comment(s);
            if (in_comment || !res.empty() && res.back().empty()) {
                res.back().append(s);
            } else {
                res.push_back(s);
            }
            in_comment = ic;
        }
        return res;
    }
};
// @lc code=end
