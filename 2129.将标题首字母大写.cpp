#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=2129 lang=cpp
 *
 * [2129] 将标题首字母大写
 */

// @lc code=start
class Solution {
public:
    string capitalizeTitle(string title)
    {
        bool is_first = true;
        string res;
        for (auto& c : title) {
            if (c == ' ') {
                is_first = true;
                res.push_back(c);
            } else if (is_first) {
                res.push_back(toupper(c));
                is_first = false;
            } else {
                res.push_back(tolower(c));
            }
        }
        return res;
    }
};
// @lc code=end
