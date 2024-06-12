#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1619 lang=cpp
 *
 * [1619] 删除某些元素后的数组均值
 */

// @lc code=start
class Solution {
public:
    double trimMean(vector<int>& arr)
    {
        int size = arr.size();
        int sumRemain = size - size / 10;
        int sum {};
        sort(arr.begin(), arr.end());
        for (int i = size / 20; i < sumRemain + size / 20; ++i) {
            sum += arr[i];
        }
        return static_cast<double>(sum) / sumRemain;
    }
};
// @lc code=end
