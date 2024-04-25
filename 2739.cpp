#include <algorithm>
using namespace std;

class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank)
    {
        int remain = mainTank;
        int res = 0;
        while (remain >= 5) {
            int to_add = remain / 5;
            res += (remain - remain % 5) * 10;
            int real_add = min(additionalTank, to_add);
            additionalTank -= real_add;
            remain = remain % 5 + real_add;
        }
        res += remain * 10;
        return res;
    }
};
