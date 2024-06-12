#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */

// @lc code=start
class Solution {
public:
    string predictPartyVictory(string senate)
    {
        int size = senate.size();
        bool Radiant { true }, Dire { true };
        int count { 0 };
        while (Radiant && Dire) {
            Radiant = false, Dire = false;
            for (auto& c : senate) {
                if (c == 'R') {
                    if (count < 0) {
                        c = '\0';
                    } else {
                        Radiant = true;
                    }
                    count++;
                } else if (c == 'D') {
                    if (count > 0) {
                        c = '\0';
                    } else {
                        Dire = true;
                    }
                    count--;
                }
            }
        }
        return Radiant ? "Radiant" : "Dire";
    }
};
// @lc code=end
