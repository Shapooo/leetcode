#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k)
    {
        int size = code.size();
        if (k == 0) {
            return vector<int>(size, 0);
        }
        int maintain = 0;
        int left {}, right {};
        if (k > 0) {
            left = 0;
            right = k;
            for (int i = 0; i < k; ++i) {
                maintain += code[i];
            }
        } else {
            left = size + k - 1;
            right = size - 1;
            for (int i = size + k - 1; i < size - 1; ++i) {
                maintain += code[i];
            }
        }
        vector<int> result(size);
        for (int i = 0; i < size; ++i) {
            maintain -= code[left];
            maintain += code[right];
            result[i] = maintain;
            left = (left + 1 + size) % size;
            right = (right + 1 + size) % size;
        }

        return result;
    }
};
// @lc code=end
