#include <cstdio>
#include <string>
using namespace std;

class Solution {
    void h(int a[3], int v)
    {
        if (v > a[0]) {
            a[2] = a[1];
            a[1] = a[0];
            a[0] = v;
        } else if (v > a[1]) {
            a[2] = a[1];
            a[1] = v;
        } else if (v > a[2]) {
            a[2] = v;
        }
    }

public:
    int maximumLength(string s)
    {
        int map[26][3] {};
        int i = 1, n = s.size(), rept = 1;
        while (i < n) {
            if (s[i] == s[i - 1]) {
                rept++;
            } else {
                h(map[s[i - 1] - 'a'], rept);
                rept = 1;
            }
            i++;
        }
        h(map[s[n - 1] - 'a'], rept);
        int res = -1;
        for (int c = 0; c < 26; ++c) {
            int tmp = -1;
            auto a = map[c];
            if (a[0] && a[0] > 2) {
                tmp = a[0] - 2;
            }
            if (a[1] && a[0] - 1 > 0) {
                tmp = max(tmp, min(a[1], a[0] - 1));
            }
            if (a[2]) {
                tmp = max(tmp, a[2]);
            }
            res = max(res, tmp);
        }
        return res;
    }
};

int main()
{
    string s = "cddedeedccedcedecdedcdeededdddcdddddcdeecdcddeecdc";
    Solution sol {};
    printf("%d\n", sol.maximumLength(s));
    return 0;
}