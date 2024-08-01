#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    int maxmiumScore(vector<int> &cards, int cnt) {
        vector<int> odds{}, evens{};
        for (auto const &c : cards) {
            if (c % 2) {
                odds.push_back(c);
            } else {
                evens.push_back(c);
            }
        }
        int i = 0;
        sort(odds.rbegin(), odds.rend());
        for (; 2 * i + 1 < odds.size(); ++i) {
            odds[i] = odds[i * 2] + odds[i * 2 + 1];
        }
        odds.erase(odds.begin() + i, odds.end());
        sort(evens.rbegin(), evens.rend());
        int oi = 0, ei = 0;
        int res{};
        while (cnt) {
            if (cnt > 1) {
                if (oi < odds.size() && ei + 1 < evens.size()) {
                    if (odds[oi] > evens[ei] + evens[ei + 1]) {
                        cnt -= 2;
                        res += odds[oi++];
                    } else {
                        cnt--;
                        res += evens[ei++];
                    }
                } else if (oi == odds.size()) {
                    cnt--;
                    res += evens[ei++];
                } else {
                    cnt -= 2;
                    res += odds[oi++];
                }
            } else {
                if (ei < evens.size()) {
                    cnt--;
                    res += evens[ei++];
                } else {
                    break;
                }
            }
        }
        if (!cnt && !(res % 2)) {
            return res;
        } else {
            return 0;
        }
    }
};

int main() {
    Solution sol{};
    vector<int> cards{7, 5};
    int cnt{2};
    sol.maxmiumScore(cards, cnt);
}