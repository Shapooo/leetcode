#include <string>
using namespace std;
class Solution {
public:
    int minLength(string s)
    {
        while (true) {
            int n = s.size();
            bool flag = false;
            auto pos = s.find("AB");
            if (pos != string::npos) {
                s.erase(pos, 2);
                flag = true;
            }
            pos = s.find("CD");
            if (pos != string::npos) {
                s.erase(pos, 2);
                flag = true;
            }
            if (!flag)
                break;
        }
        return s.size();
    }
};