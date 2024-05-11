#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2105 lang=cpp
 *
 * [2105] 给植物浇水 II
 */

// @lc code=start
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB)
    {
        int n = plants.size();
        int remA = capacityA;
        int remB = capacityB;
        int res {};
        for (int i = 0; i < n / 2; ++i) {
            if (remA < plants[i]) {
                ++res;
                remA = capacityA - plants[i];
            } else {
                remA -= plants[i];
            }
        }
        for (int i = n - 1; i >= (n + 1) / 2; --i) {
            if (remB < plants[i]) {
                ++res;
                remB = capacityB - plants[i];
            } else {
                remB -= plants[i];
            }
        }
        res += n % 2 && remB < plants[n / 2] && remA < plants[n / 2];
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> plants { 1, 2, 4, 4, 5 };
    int capacityA = 6, capacityB = 5;
}