#include <vector>
using namespace std;
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors)
    {
        int res = divisors[0];
        int max_cnt = 0;
        for (auto const& div : divisors) {
            int cnt = 0;
            for (auto const& n : nums) {
                cnt += !(n % div);
            }
            if (cnt > max_cnt || cnt == max_cnt && div < res) {
                max_cnt = cnt;
                res = div;
            }
        }
        return res;
    }
};