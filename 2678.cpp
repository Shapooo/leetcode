#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int countSeniors(vector<string>& details)
    {
        int res {};
        for (auto& s : details) {
            if ((s[11] - '0') * 10 + (s[12] - '0') > 60) {
                res++;
            }
        }
        return res;
    }
};