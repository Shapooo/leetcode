#include <cstdio>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2511 lang=cpp
 *
 * [2511] 最多可以摧毁的敌人城堡数目
 */

// @lc code=start
class Solution {
public:
    int captureForts(vector<int>& forts)
    {
        int n = forts.size();
        int i = 0;
        int start = -2;
        int ops = 0;
        int res = 0;
        while (i < n) {
            switch (forts[i]) {
            case -1: {
                if (ops && start == 1) {
                    res = max(res, ops);
                }
                ops = 0;
                start = -1;
                break;
            }
            case 0: {
                ops++;
                break;
            }
            case 1: {
                if (ops && start == -1) {
                    res = max(res, ops);
                }
                ops = 0;
                start = 1;
                break;
            }
            }
            i++;
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> forts { 1, 0, 0, -1, 0, 0, 0, 0, 1 };
    printf("%d\n", sol.captureForts(forts));
    forts = { 0, 0, 1, -1 };
    // printf("%d\n", sol.captureForts(forts));
}