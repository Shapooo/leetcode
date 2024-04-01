#include <vector>
using namespace std;
class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations)
    {
        for (auto& v : operations) {
            int sent = gem[v[0]] / 2;
            gem[v[0]] -= sent;
            gem[v[1]] += sent;
        }
        int ma {}, mi { 1000'001 };
        for (auto& n : gem) {
            ma = max(ma, n);
            mi = min(mi, n);
        }
        return ma - mi;
    }
};