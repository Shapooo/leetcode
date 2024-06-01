#include <algorithm>
#include <cstdio>
using namespace std;
class Solution {
public:
    int distributeCandies(int n, int limit)
    {
        int a = min(limit, n);
        int res {};
        for (; a >= (n + 2) / 3; --a) {
            int b = (n - a + 1) / 2;
            for (; b <= a && b <= n - a; ++b) {
                int c = n - a - b;
                if (a == b && b == c) {
                    res += 1;
                } else if (a == b || b == c) {
                    res += 3;
                } else {
                    res += 6;
                }
            }
        }
        return res;
    }
};

int main()
{
    int n = 5, limit = 2;
    n = 3, limit = 3;
    Solution sol {};
    sol.distributeCandies(n, limit);
    return {};
}