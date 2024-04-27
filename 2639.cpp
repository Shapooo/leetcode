#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    int get_length(int n)
    {
        if (n == 0) {
            return 1;
        }
        int res = n > 0 ? 0 : 1;
        n = abs(n);
        while (n > 0) {
            n /= 10;
            res++;
        }
        return res;
    }

public:
    vector<int> findColumnWidth(vector<vector<int>>& grid)
    {
        int n = grid[0].size(), m = grid.size();
        vector<int> res(n);
        for (auto const& vec : grid) {
            for (int i = 0; i < n; ++i) {
                auto l = get_length(vec[i]);
                res[i] = max(res[i], l);
            }
        }

        return res;
    }
};
