#include <vector>
using namespace std;
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums)
    {
        long long res = 1;
        int idx = 0;
        int n = nums.size();
        while (idx < n && nums[idx] != 1) {
            idx++;
        }
        if (idx == n) {
            return 0;
        }
        int last = idx;
        idx++;
        while (idx < n) {
            if (nums[idx] == 1) {
                res = res * (idx - last) % 1000'000'007;
                last = idx;
            }
            idx++;
        }
        return res;
    }
};