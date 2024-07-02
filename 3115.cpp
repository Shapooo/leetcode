#include <iostream>
#include <vector>
using namespace std;

constexpr int PRIME[] = {
    0,
    0,
    1,
    1,
    0,
    1,
    0,
    1,
    0,
    0,
    0,
    1,
    0,
    1,
    0,
    0,
    0,
    1,
    0,
    1,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    1,
    0,
    1,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    1,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
};

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums)
    {
        int l, r;
        for (int i = 0; i < nums.size(); ++i) {
            if (PRIME[nums[i]]) {
                l = i;
                break;
            }
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (PRIME[nums[i]]) {
                r = i;
                break;
            }
        }
        return r - l;
    }
};

int main()
{
    Solution sol {};
    vector<int> nums { 4, 2, 9, 5, 3 };
    cout << sol.maximumPrimeDifference(nums) << endl;
    return 0;
}
