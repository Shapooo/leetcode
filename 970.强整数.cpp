#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 */

// @lc code=start
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        int smaller = min(x, y), bigger = max(x, y);
        if (smaller == 1 && bigger == 1) {
            if (bound < 2) {
                return {};
            } else {
                return { 2 };
            }
        }
        vector<int> res {};
        if (smaller == 1) {
            int tmp = 1;
            while (tmp <= bound - 1) {
                res.push_back(tmp + 1);
                tmp *= bigger;
            }
            return res;
        }
        unordered_set<int> set {};
        int tmp1 = 1;
        while (tmp1 <= bound - 1) {
            int tmp2 = 1;
            while (tmp2 <= bound - tmp1) {
                set.emplace(tmp1 + tmp2);
                tmp2 *= smaller;
            }
            tmp1 *= bigger;
        }
        for (auto&& i : set) {
            res.push_back(i);
        }

        return res;
    }
};
// @lc code=end

#include <iostream>
int main(int argc, char const* argv[])
{
    Solution sol;
    int x = 2, y = 3, bound = 10;
    for (auto&& i : sol.powerfulIntegers(x, y, bound)) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
