#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold)
    {
        int n = nums.size();
        int res {};
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= threshold && nums[i] % 2 == 0) {
                res = max(res, 1);
                for (int j = 1; j + i < n; ++j) {
                    // printf("%d %d\n", i, j);
                    if (nums[i + j] <= threshold && nums[i + j] % 2 == j % 2) {
                        res = max(res, j + 1);
                    } else {
                        break;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums { 2, 2 };
    int threshold = 5;
    int res = sol.longestAlternatingSubarray(nums, threshold);
    printf("%d\n", res);
    return 0;
}