#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2079 lang=cpp
 *
 * [2079] 给植物浇水
 */

// @lc code=start
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity)
    {
        int res {}, n = plants.size(), remain = capacity;
        for (int i = 0; i < n; ++i) {
            if (remain >= plants[i]) {
                remain -= plants[i];
                res += 1;
            } else {
                remain = capacity - plants[i];
                res += i * 2 + 1;
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> plants = { 2, 2, 3, 3 };
    int capacity = 5;
    printf("%d\n", sol.wateringPlants(plants, capacity));
    return 0;
}