#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=2063 lang=cpp
 *
 * [2063] 所有子字符串中的元音
 */

// @lc code=start
class Solution {
public:
    long long countVowels(string word)
    {
        long long n = word.size();
        long long res {};
        for (long long i = 0; i < n; ++i) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                res += (i + 1) * (n - i);
            }
        }
        return res;
    }
};
// @lc code=end
