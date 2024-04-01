#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1865 lang=cpp
 *
 * [1865] 找出和为指定值的下标对
 */

// @lc code=start
class FindSumPairs {
    vector<int> nums1, nums2;
    // int n2map[100'001] {};
    unordered_map<int, int> n2map {};

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
        : nums1(nums1)
        , nums2(nums2)
    {
        for (auto& n : nums2) {
            n2map[n]++;
        }
    }

    void add(int index, int val)
    {
        n2map[nums2[index]]--;
        nums2[index] += val;
        n2map[nums2[index]]++;
    }

    int count(int tot)
    {
        int res = 0;
        for (auto& n : nums1) {
            if (n < tot) {
                res += n2map[tot - n];
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
// @lc code=end
