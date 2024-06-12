#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        int size2 = nums2.size();
        int size1 = nums1.size();
        vector<int> result(size1);
        unordered_map<int, int> map { { nums2[size2 - 1], -1 } };
        for (int i = size2 - 2; i >= 0; --i) {
            int val = nums2[i + 1];
            while (true) {
                if (val == -1) {
                    break;
                } else if (nums2[i] >= val) {
                    val = map[val];
                } else {
                    break;
                }
            }
            map[nums2[i]] = val;
        }
        for (int i = 0; i < size1; ++i) {
            result[i] = map[nums1[i]];
        }
        return result;
    }
};
// @lc code=end
