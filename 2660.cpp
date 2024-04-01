#include <vector>
using namespace std;

class Solution {
    int sum(vector<int>& v)
    {
        int len = v.size();
        int last_perfect = -3;
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (i - last_perfect <= 2) {
                res += v[i] * 2;
            } else {
                res += v[i];
            }
            if (v[i] == 10) {
                last_perfect = i;
            }
        }
        return res;
    }

public:
    int isWinner(vector<int>& player1, vector<int>& player2)
    {
        int p1score = sum(player1);
        int p2score = sum(player2);
        if (p1score > p2score) {
            return 1;
        } else if (p1score < p2score) {
            return 2;
        } else {
            return 0;
        }
    }
};