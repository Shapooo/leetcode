#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1333 lang=cpp
 *
 * [1333] 餐厅过滤器
 */

// @lc code=start
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance)
    {
        int n = restaurants.size(), l {}, r {};
        for (; r < n; ++r) {
            if (veganFriendly && !restaurants[r][2] || maxPrice < restaurants[r][3] || maxDistance < restaurants[r][4]) {
                continue;
            } else {
                swap(restaurants[l], restaurants[r]);
                l++;
            }
        }
        restaurants.erase(restaurants.begin() + l, restaurants.end());
        sort(restaurants.begin(), restaurants.end(), [](auto lhs, auto rhs) {
            if (lhs[1] == rhs[1]) {
                return lhs[0] > rhs[0];
            } else {
                return lhs[1] > rhs[1];
            }
        });
        vector<int> res {};
        for (auto& r : restaurants) {
            res.emplace_back(r[0]);
        }
        return res;
    }
};
// @lc code=end
