#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights)
    {
        long long pre_min_sum[1001] {}, suf_min_sum[1001] {};
        int n = maxHeights.size();
        long long pre_sum {}, suf_sum {};
        for (int i = 0, min_maxHeight = maxHeights[0]; i < n; ++i) {
            min_maxHeight = min(min_maxHeight, maxHeights[i]);
            pre_min_sum[i] += min_maxHeight;
        }
        for (auto& n : pre_min_sum) {
            printf("%lld ", n);
        }
        for (int i = n - 1, min_maxHeight = maxHeights[n - 1]; i >= 0; --i) {
            min_maxHeight = min(min_maxHeight, maxHeights[i]);
            suf_min_sum[i] += min_maxHeight;
        }
        for (auto& n : suf_min_sum) {
            printf("%lld ", n);
        }
        long long res { suf_min_sum[0] };
        printf("%lld\n", res);
        for (int i = 1; i < n; ++i) {
            long long tmp = pre_min_sum[n - 1] - pre_min_sum[i - 1] + suf_min_sum[0] - suf_min_sum[i];
            res = max(res, tmp);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> maxHeights = { 6, 5, 3, 9, 2, 7 };
    printf("%lld\n", sol.maximumSumOfHeights(maxHeights));
}