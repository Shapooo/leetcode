#include <string>
using namespace std;
class Solution {
public:
    string makeSmallestPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            s[r] = s[l] = min(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};