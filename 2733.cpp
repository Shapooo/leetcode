#include <algorithm>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums)
    {
        if (nums.size() < 3) {
            return -1;
        }
        set<int> a {};
        for (auto& n : nums) {
            a.insert(n);
        }
        if (a.size() < 3) {
            return -1;
        }
        return *(++a.begin());
    }
};