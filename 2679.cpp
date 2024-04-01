#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums)
    {
        for (auto& v : nums) {
            sort(v.begin(), v.end());
        }
        auto l = nums[0].size();
        int res {};
        for (int i = 0; i < l; ++i) {
            int m = 0;
            for (auto& v : nums) {
                m = max(m, v.back());
                v.pop_back();
            }
            res += m;
        }
        return res;
    }
};
