#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */

// @lc code=start
class Solution {
public:
    int longestMountain(vector<int>& arr)
    {
        bool increased = false;
        bool decreased = true;
        int size = arr.size();
        int result = 0;
        int start = 0;
        for (int i = 1; i < size; ++i) {
            if (arr[i] > arr[i - 1]) {
                if (decreased) {
                    increased = true;
                    decreased = false;
                    start = i - 1;
                }
            } else if (arr[i] < arr[i - 1]) {
                if (increased) {
                    decreased = true;
                    result = max(result, i - start + 1);
                }
            } else {
                increased = false;
                decreased = true;
            }
        }
        return result;
    }
};
// @lc code=end
