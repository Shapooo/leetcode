#include <iostream>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */

// @lc code=start
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time)
    {
        int64_t set[60] {};
        int res {};
        for (auto&& i : time) {
            set[i % 60]++;
        }
        for (size_t i = 1; i < 30; i++) {
            res += set[i] * set[60 - i];
        }
        res += set[0] * (set[0] - 1) / 2 + set[30] * (set[30] - 1) / 2;
        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution sol;
    vector<int> time { 30, 20, 150, 100, 40 };
    cout << sol.numPairsDivisibleBy60(time) << endl;
    return 0;
}
