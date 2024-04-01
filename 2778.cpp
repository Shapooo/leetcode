#include <vector>
using namespace std;
class Solution {
public:
    int sumOfSquares(vector<int>& nums)
    {
        int n = nums.size();
        int res {};
        for (int i = 0; i < n; ++i) {
            if (n % (i + 1) == 0) {
                res += nums[i] * nums[i];
            }
        }
        return res;
    }
};