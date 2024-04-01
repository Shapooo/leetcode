#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                nums[i] += d;
            } else {
                nums[i] -= d;
            }
        }
        sort(nums.begin(), nums.end());
        long long MOD = 1000'000'007;
        long long res {}, sum = nums[0];
        for (int i = 1; i < n; ++i) {
            res = ((long long)i * nums[i] - sum + res) % MOD;
            sum += nums[i];
        }
        return res;
    }
};