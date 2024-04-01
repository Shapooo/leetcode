#include <vector>
using namespace std;
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries)
    {
        int nums[100'000] {};
        int cnt = 0;
        vector<int> res {};
        for (auto& v : queries) {
            int idx = v[0];
            int color = v[1];
            int old_color = nums[idx];
            nums[idx] = color;
            if (idx > 0) {
                if (old_color && nums[idx - 1] == old_color) {
                    cnt--;
                }
                if (color == nums[idx - 1]) {
                    cnt++;
                }
            }
            if (idx < n - 1) {
                if (old_color && nums[idx + 1] == old_color) {
                    cnt--;
                }
                if (color == nums[idx + 1]) {
                    cnt++;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};