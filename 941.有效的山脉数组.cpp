#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& arr)
    {
        int size = arr.size();
        if (size < 3) {
            return false;
        }
        if (arr[0] > arr[1] || arr[size - 1] > arr[size - 2]) {
            return false;
        }
        int left = 0, right = size - 1;
        while (left < right) {
            if (arr[left] == arr[left + 1]) {
                return false;
            } else if (arr[left] > arr[left + 1]) {
                break;
            }
            left++;
        }
        while (right > left) {
            if (arr[right] >= arr[right - 1]) {
                return false;
            }
            right--;
        }
        return true;
    }
};
// @lc code=end
