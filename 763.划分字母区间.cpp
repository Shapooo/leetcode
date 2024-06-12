#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> result {};
        int size = s.size();
        int map[26] {};
        for (int i = 0; i < size; ++i) {
            map[s[i] - 'a'] = i;
        }
        int farest = 0, last = -1;
        for (int i = 0; i < size; ++i) {
            farest = max(farest, map[s[i] - 'a']);
            if (farest == i) {
                result.push_back(i - last);
                last = i;
            }
        }
        return result;
    }
};
// @lc code=end
