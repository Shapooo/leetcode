#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    inline int iterate(int n)
    {
        int result = 0;
        while (n) {
            auto rem = (n % 10);
            result += rem * rem;
            n = n / 10;
        }
        return result;
    }

    bool isHappy(int n)
    {
        unordered_set<int> set {};
        while (n != 1) {
            n = iterate(n);
            if (set.find(n) != set.cend()) {
                return false;
            } else {
                set.emplace(n);
            }
        }
        return true;
    }
};
// @lc code=end
