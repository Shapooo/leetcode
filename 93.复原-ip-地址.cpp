#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() < 4 || s.size() > 12)
            return _ans;
        _helper(s, 0);
        return _ans;
    }
    void _helper(string& s, int start)
    {
        int size = s.size();
        if (_path.size() == 4) {
            if (size == start) {
                string tmp {};
                for (auto& i : _path) {
                    tmp.append(to_string(i));
                    tmp.push_back('.');
                }
                tmp.pop_back();
                _ans.push_back(move(tmp));
            }
            return;
        }
        if (s.size() - start > (4 - _path.size()) * 3) {
            return;
        }

        if (s[start] == '0') {
            _path.push_back(0);
            _helper(s, start + 1);
            _path.pop_back();
        } else {
            int sum = 0;
            for (int i = start; i < size && i < start + 3; ++i) {
                sum *= 10;
                sum += s[i] - '0';
                if (sum > 255) {
                    break;
                }
                _path.push_back(sum);
                _helper(s, i + 1);
                _path.pop_back();
            }
        }
    }
    vector<string> _ans {};
    vector<int> _path {};
};
// @lc code=end
