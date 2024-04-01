#include <vector>
using namespace std;
class Solution {
public:
    int alternatingSubarray(vector<int>& nums)
    {
        int a, b;
        int n = nums.size();
        int l = 1;
        int res = -1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] + (l % 2 ? 1 : -1) == nums[i + 1]) {
                l++;
                res = max(res, l);
            } else if (nums[i] + 1 == nums[i + 1]) {
                l = 2;
                res = max(res, l);
            } else {
                l = 1;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = { 6, 12, 2, 3, 8, 9, 10, 10, 2, 1 };
    Solution sol {};
    sol.alternatingSubarray(nums);
}