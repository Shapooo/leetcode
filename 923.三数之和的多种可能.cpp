#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=923 lang=cpp
 *
 * [923] 三数之和的多种可能
 */

// @lc code=start
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target)
    {
        unordered_map<int, int> map {};
        vector<int> vec {};
        for (auto& n : arr) {
            map[n]++;
        }
        sort(arr.begin(), arr.end());
        auto last = unique(arr.begin(), arr.end());
        arr.erase(last, arr.end());
        int n = arr.size();
        long long res {}, MOD = 1000'000'007;
        for (int i = 0; i < n; ++i) {
            if ((target - arr[i]) / 2 < arr[i]) {
                break;
            }
            for (int j = i; j < n; ++j) {
                int k = target - arr[i] - arr[j];
                if (k < arr[j]) {
                    break;
                }
                auto it = map.find(k);
                if (it != map.end()) {
                    if (arr[i] == arr[j] && arr[i] == k) {
                        res = (res + (long long)it->second * (it->second - 1) * (it->second - 2) / 6) % MOD;
                    } else if (arr[i] == arr[j]) {
                        auto it2 = map.find(arr[i]);
                        res = (res + (long long)it2->second * (it2->second - 1) / 2 * it->second) % MOD;
                    } else if (arr[j] == k) {
                        auto it2 = map.find(arr[i]);
                        res = (res + (long long)it2->second * (it->second - 1) * it->second / 2) % MOD;
                    } else {
                        auto it2 = map.find(arr[i]);
                        auto it3 = map.find(arr[j]);
                        res = (res + (long long)it->second * it2->second * it3->second) % MOD;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> arr { 2, 1, 3 };
    int target = 6;
    printf("%d\n", sol.threeSumMulti(arr, target));
}