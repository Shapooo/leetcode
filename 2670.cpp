#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums)
    {
        int map[51] {}, pre[51] {}, suf[51] {};
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += map[nums[i]] == 0;
            map[nums[i]] = 1;
            pre[i] = count;
        }
        memset(map, 0, sizeof(map));
        for (int i = nums.size() - 1, count = 0; i >= 0; --i) {
            count += map[nums[i]] == 0;
            map[nums[i]] = 1;
            suf[i] = count;
        }
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size() - 1; ++i) {
            res[i] = pre[i] - suf[i + 1];
        }
        res[nums.size() - 1] = pre[nums.size() - 1];
        return res;
    }
};