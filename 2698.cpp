#include <cstdio>
#include <string>
using namespace std;
class Solution {
    bool check(int x)
    {
        string s = to_string(x * x);
        return rec(s, 0, x, 0);
    }

    bool rec(string& s, int start, int target, int acc)
    {
        int len = s.size();
        if (start == len) {
            return acc == target;
        }
        int val = 0;
        for (; start < len; ++start) {
            val *= 10;
            val += s[start] - '0';
            if (acc + val > target) {
                break;
            }
            if (rec(s, start + 1, target, acc + val)) {
                return true;
            }
        }
        return false;
    }

public:
    int punishmentNumber(int n)
    {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (check(i)) {
                res += i * i;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol {};
    for (int i = 1; i <= 1000; ++i) {
        printf("%d, ", sol.punishmentNumber(i));
    }
    return 0;
}