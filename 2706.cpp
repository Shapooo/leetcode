#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int buyChoco(vector<int>& prices, int money)
    {
        sort(prices.begin(), prices.end());
        int a = money - prices[0] - prices[1];
        if (a < 0)
            return money;
        else
            return a;
    }
};
