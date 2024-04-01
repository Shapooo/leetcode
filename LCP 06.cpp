#include <vector>
using namespace std;
class Solution {
public:
    int minCount(vector<int>& coins)
    {
        int res {};
        for (auto& n : coins) {
            res += (n + 1) / 2;
        }
        return res;
    }
};