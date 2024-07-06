#include <vector>
using namespace std;
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums)
    {
        int n = nums.size(), idx = 1;
        long long res = 0, cnt = 1;
        while (idx < n) {
            if (nums[idx] == nums[idx - 1]) {
                res += cnt * (cnt + 1) / 2;
                cnt = 1;
            } else {
                ++cnt;
            }
            ++idx;
        }
        res += cnt * (cnt + 1) / 2;
        return res;
    }
};