#include <bitset>
#include <vector>
using namespace std;
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k)
    {
        int res {};
        for (int i = 0; i < nums.size(); ++i) {
            auto cnt = static_cast<bitset<32>>(i).count();
            if (cnt == k) {
                res += nums[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 1, 2, 3, 4 };
    printf("%d\n", sol.sumIndicesWithKSetBits(nums, 2));
    nums = { 5, 10, 1, 5, 2 };
    printf("%d\n", sol.sumIndicesWithKSetBits(nums, 1));
}