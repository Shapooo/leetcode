#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
class Solution {
    vector<int> intersect(vector<int>& a, vector<int>& b)
    {
        return { max(a[0], b[0]), min(a[1], b[1]) };
    }
    int compare(vector<int>& a, vector<int>& b)
    {
        if (a[1] < b[0]) {
            return -1;
        } else if (a[0] > b[1]) {
            return 1;
        } else {
            return 0;
        }
    }

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList)
    {
        int nf = firstList.size(), ns = secondList.size();
        if (!nf || !ns) {
            return {};
        }
        int idx_f {}, idx_s {};
        vector<vector<int>> res {};
        while (idx_f < nf && idx_s < ns) {
            int cmp = compare(firstList[idx_f], secondList[idx_s]);
            if (!cmp) {
                res.emplace_back(intersect(firstList[idx_f], secondList[idx_s]));
                int t1 = firstList[idx_f][1], t2 = secondList[idx_s][1];
                if (t1 == t2) {
                    idx_f++, idx_s++;
                } else if (t1 > t2) {
                    idx_s++;
                } else {
                    idx_f++;
                }
            } else if (cmp > 0) {
                idx_s++;
            } else {
                idx_f++;
            }
        }
        return res;
    }
};
// @lc code=end
