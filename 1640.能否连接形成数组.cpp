#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1640 lang=cpp
 *
 * [1640] 能否连接形成数组
 */

// @lc code=start
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces)
    {
        unordered_map<int, vector<int>*> map {};
        int size = arr.size();
        for (auto& v : pieces) {
            map[v[0]] = &v;
        }
        int i = 0;
        while (i < size) {
            auto it = map.find(arr[i]);
            if (it == map.cend()) {
                return false;
            } else {
                for (auto& v : *(it->second)) {
                    if (v != arr[i]) {
                        return false;
                    }
                    i++;
                }
            }
        }
        return i == size;
    }
};
// @lc code=end
