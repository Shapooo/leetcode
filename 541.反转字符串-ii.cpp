#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    inline void _reverse(string& s, int i, int j)
    {
        if (j - i < 2)
            return;
        int count = i + (j - i) / 2;
        j--;
        for (; i < count;) {
            swap(s[i++], s[j--]);
        }
    }
    string reverseStr(string s, int k)
    {
        int index = 0;
        int size = s.size();
        while (index < size) {
            if (index + k <= size) {
                _reverse(s, index, index + k);
            } else {
                _reverse(s, index, size);
            }
            index += 2 * k;
        }

        return s;
    }
};
// @lc code=end
