/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

// @lc code=start
class Solution {
public:
    int maximumSwap(int num)
    {
        int vec[10];
        int size = 0;
        int tmp { num };
        for (; tmp; ++size) {
            vec[size] = tmp % 10;
            tmp /= 10;
        }
        int result { 0 };
        bool exchanged = false;
        for (int i = size - 1; i >= 0; --i) {
            if (!exchanged) {
                int max_i = -1;
                for (int j = 0; j < i; ++j) {
                    if (max_i != -1 && vec[j] > vec[max_i] || max_i == -1 && vec[j] > vec[i]) {
                        max_i = j;
                    }
                }
                if (max_i != -1) {
                    auto tmp = vec[i];
                    vec[i] = vec[max_i];
                    vec[max_i] = tmp;
                    exchanged = true;
                }
            }
            result *= 10;
            result += vec[i];
        }
        return result;
    }
};
// @lc code=end
