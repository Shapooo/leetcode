class Solution {
public:
    int sumOfMultiples(int n)
    {
        int res {};
        for (int i = 1; i <= n; ++i) {
            if (i % 3 && i % 5 && i % 7) {
                continue;
            }
            res += i;
        }
        return res;
    }
};