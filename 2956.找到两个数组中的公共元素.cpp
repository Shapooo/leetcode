#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2956 lang=cpp
 *
 * [2956] 找到两个数组中的公共元素
 */

// @lc code=start
class Solution {
public:
  vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2) {
    int m1[101]{}, m2[101]{};

    for (auto const &x : nums1) {
      m1[x]++;
    }
    for (auto const &x : nums2) {
      m2[x]++;
    }
    int c1{}, c2{};
    for (int i = 1; i <= 100; i++) {
      if (m1[i] && m2[i]) {
        c1 += m1[i];
        c2 += m2[i];
      }
    }
    return {c1, c2};
  }
};
// @lc code=end