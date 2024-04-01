#include <vector>
using namespace std;
class Solution {
public:
    int countPairs(vector<int>& nums, int target)
    {
        int n = nums.size();
        int res {};
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] < target) {
                    res++;
                }
            }
        }
        return res;
    }
};