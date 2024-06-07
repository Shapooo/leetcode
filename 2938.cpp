#include <string>
using namespace std;

class Solution {
public:
    long long minimumSteps(string s)
    {
        int wc {}, n = s.size();
        long long res {};
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                res += i - wc;
                wc++;
            }
        }
        return res;
    }
};
