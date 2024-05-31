#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid)
    {
        int set[2501] {}, n = grid.size();
        int dup {}, disap {};
        for (auto const& vec : grid) {
            for (auto const& v : vec) {
                set[v]++;
            }
        }
        for (int i = 1; i <= n * n; ++i) {
            if (set[i] == 2) {
                dup = i;
            } else if (!set[i]) {
                disap = i;
            }
        }
        return { dup, disap };
    }
};