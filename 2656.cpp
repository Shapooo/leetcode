#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k)
    {
        int max_val = *max_element(nums.begin(), nums.end());
        return (max_val + max_val + k - 1) * k / 2;
    }
};
