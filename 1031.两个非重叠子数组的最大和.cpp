#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */

// @lc code=start
class Solution {
    int helper(vector<int>& nums, int firstLen, int secondLen)
    {
        int res {};
        auto len = nums.size();
        int accF = 0, accS = 0;
        vector<int> mem1(len), mem2(len);
        for (size_t i = firstLen; i <= len - secondLen; i++) {
            if (i == firstLen) {
                for (size_t j = 0; j < firstLen; j++) {
                    accF += nums[j];
                }
            } else {
                accF -= nums[i - firstLen - 1];
                accF += nums[i - 1];
            }
            mem1[i] = max(mem1[i - 1], accF);
        }
        for (size_t i = len; i >= firstLen + secondLen; i--) {
            if (i == len) {
                for (size_t j = len - secondLen; j < len; j++) {
                    accS += nums[j];
                }
                mem2[i - secondLen] = accS;
            } else {
                accS -= nums[i];
                accS += nums[i - secondLen];
                mem2[i - secondLen] = max(mem2[i - secondLen + 1], accS);
            }
        }
        for (size_t i = firstLen; i <= len - secondLen; i++) {
            res = max(res, mem1[i] + mem2[i]);
        }

        return res;
    }

public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen)
    {
        if (firstLen == secondLen) {
            return helper(nums, firstLen, secondLen);
        }
        if (nums.size() == firstLen + secondLen) {
            int res = 0;
            for (auto&& i : nums) {
                res += i;
            }
            return res;
        }
        return max(helper(nums, firstLen, secondLen), helper(nums, secondLen, firstLen));
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution sol;
    vector<int> nums = { 0, 6, 5, 2, 2, 5, 1, 9, 4 };
    int firstLen = 1, secondLen = 2;
    cout << sol.maxSumTwoNoOverlap(nums, firstLen, secondLen) << endl;

    nums = { 3, 8, 1, 3, 2, 1, 8, 9, 0 };
    firstLen = 3, secondLen = 2;
    cout << sol.maxSumTwoNoOverlap(nums, firstLen, secondLen) << endl;
    nums = { 2, 1, 5, 6, 0, 9, 5, 0, 3, 8 };
    firstLen = 4, secondLen = 3;
    cout << sol.maxSumTwoNoOverlap(nums, firstLen, secondLen) << endl;
    nums = { 1, 0, 3 };
    firstLen = 1, secondLen = 2;
    cout << sol.maxSumTwoNoOverlap(nums, firstLen, secondLen) << endl;
    return 0;
}
