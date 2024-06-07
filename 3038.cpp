#include <vector>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums)
    {
        int n = nums.size() / 2;
        int target = nums[0] + nums[1];
        for (int i = 0; i < n; ++i) {
            if (nums[i * 2] + nums[i * 2 + 1] != target) {
                return i;
            }
        }
        return n;
    }
};