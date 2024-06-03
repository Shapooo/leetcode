#include <cmath>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 *
 * [1103] 分糖果 II
 */

// @lc code=start
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        // int n = static_cast<int>(sqrt(static_cast<double>(candies) * 8 + 1) - 1) / 2;
        // int p = n / num_people, begin = p + num_people * num_people * (num_people - 1) / 2;
        // int rp = n % num_people;
        // vector<int> res(num_people);
        // for (int i = 0; i < rp; ++i) {
        //     res[i] = begin + p * i;
        // }
        // res[rp] = candies - n * (n + 1) / 2;
        // return res;
        vector<int> res(num_people);
        int i = 1;
        for (; candies >= i; ++i) {
            candies -= i;
            res[(i - 1) % num_people] += i;
        }
        res[(i - 1) % num_people] += candies;
        return res;
    }
};
// @lc code=end
