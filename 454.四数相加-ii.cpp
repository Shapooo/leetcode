#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
        vector<int>& nums4)
    {
        int size = nums1.size();
        unordered_map<int, int> map12;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                map12[nums1[i] + nums2[j]]++;
            }
        }
        int result = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                auto iter = map12.find(-(nums3[i] + nums4[j]));
                if (iter != map12.end()) {
                    result += iter->second;
                }
            }
        }

        return result;
    }
};
// @lc code=end
