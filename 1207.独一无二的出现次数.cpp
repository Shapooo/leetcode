#include <bitset>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int, int> map {};
        for (auto& i : arr) {
            map[i]++;
        }
        bitset<1000> occ {};
        for (auto& p : map) {
            if (occ[p.second] == 0) {
                occ[p.second] = 1;
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
