#include <vector>
using namespace std;

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages)
    {
        int res {}, cdown {};
        for (auto const& bp : batteryPercentages) {
            int nbp = bp - cdown;
            if (nbp > 0) {
                res++;
                cdown++;
            }
        }
        return res;
    }
};