#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumLength(string s)
    {
        vector<vector<int>> map(26, vector<int>());
        int i = 1, n = s.size();
        int rept { 1 };
        while (i < n) {
            if (s[i] == s[i - 1]) {
                rept++;
            } else {
                map[s[i - 1] - 'a'].push_back(rept);
                rept = 1;
            }
            i++;
        }
        map[s[n - 1] - 'a'].push_back(rept);
        int res { -1 };
        for (auto& v : map) {
            if (v.size() == 0) {
                continue;
            }
            sort(v.rbegin(), v.rend());
            int tmp = -1;
            if (v.size() >= 1) {
                tmp = v[0] - 2 > 0 ? v[0] - 2 : tmp;
            }
            if (v.size() >= 2) {
                auto t = min(v[1], v[0] - 1);
                tmp = t > 0 ? max(tmp, min(v[1], v[0] - 1)) : tmp;
            }
            if (v.size() >= 3) {
                tmp = max(tmp, v[2]);
            }
            res = max(res, tmp);
        }
        return res;
    }
};

int main()
{
    string s = "abcccccdddd";
    Solution sol {};
    printf("%d\n", sol.maximumLength(s));
    return 0;
}