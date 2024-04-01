#include <vector>
using namespace std;
class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target)
    {
        int res {};
        for (auto& n : hours) {
            res += n >= target;
        }
        return res;
    }
};