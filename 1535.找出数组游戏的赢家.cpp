#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1535 lang=cpp
 *
 * [1535] 找出数组游戏的赢家
 */

// @lc code=start
class Solution {
public:
    int getWinner(vector<int>& arr, int k)
    {
        int n = arr.size();
        if (k >= n - 1) {
            return *max_element(arr.begin(), arr.end());
        }
        int cnt {}, idx = 1;
        int m = arr[0];
        queue<int> q {};
        for (int i = 1; i < n; ++i) {
            q.push(arr[i]);
        }
        while (true) {
            if (m > q.front()) {
                q.push(q.front());
                q.pop();
                cnt++;
            } else {
                q.push(m);
                m = q.front();
                q.pop();
                cnt = 1;
            }
            if (cnt == k) {
                return m;
            }
            idx++;
        }
        return m;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<int> arr { 2, 1, 3, 5, 4, 6, 7 };
    int k = 2;
    sol.getWinner(arr, k);
    return 0;
}