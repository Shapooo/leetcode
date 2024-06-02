#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType)
    {
        unordered_set<int> types {};
        for (auto const& type : candyType) {
            types.insert(type);
        }
        return min(candyType.size() / 2, types.size());
    }
};
// @lc code=end
