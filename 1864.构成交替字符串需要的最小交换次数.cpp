#include <cstdio>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=1864 lang=cpp
 *
 * [1864] 构成交替字符串需要的最小交换次数
 */

// @lc code=start
class Solution {
public:
    int minSwaps(string s)
    {
        int zs_cnt = 0, zs_z = 0, zs_o = 0;
        int os_cnt = 0, os_z = 0, os_o = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (i % 2) {
                    if (os_z) {
                        os_z--;
                    } else {
                        os_o++, os_cnt++;
                    }
                } else {
                    if (zs_z) {
                        zs_z--;
                    } else {
                        zs_o++, zs_cnt++;
                    }
                }
            } else if (s[i] == '0') {
                if (i % 2) {
                    if (zs_o) {
                        zs_o--;
                    } else {
                        zs_z++, zs_cnt++;
                    }
                } else {
                    if (os_o) {
                        os_o--;
                    } else {
                        os_z++, os_cnt++;
                    }
                }
            }
        }
        if ((os_z || os_o) && (zs_z || zs_o)) {
            return -1;
        } else if (os_z || os_o) {
            return zs_cnt;
        } else if (zs_o || zs_z) {
            return os_cnt;
        }
        return min(zs_cnt, os_cnt);
    }
};
// @lc code=end

int main()
{
    string s = "00011110110110000000000110110101011101111011111101010010010000000000000001101101010010001011110000001101111111110000110101101101001011000011111011101101100110011111110001100110001110000000001100010111110100111001001111100001000110101111010011001";
    Solution sol {};
    printf("%d\n", sol.minSwaps(s));
}