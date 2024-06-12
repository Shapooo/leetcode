#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
        if (size1 + size2 != size3) {
            return false;
        }
        for (int i = 0, j = 0, k = 0; i < size3; ++i) {
            if (j < size1 && s1[j] == s3[i]) {
                j++;
            } else if (k < size2 && s2[k] == s3[i]) {
                k++;
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
