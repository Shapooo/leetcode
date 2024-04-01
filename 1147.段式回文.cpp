#include <iostream>
#include <string>
#include <string_view>
using namespace std;
/*
 * @lc app=leetcode.cn id=1147 lang=cpp
 *
 * [1147] 段式回文
 */

// @lc code=start
class Solution {
  int rec(string_view text) {
    // cout << "rec: " << text << endl;
    auto len = text.size();
    if (len == 0) {
      return 0;
    }
    int l = 0, r = len - 1;
    while (l < r) {
      if (text[0] == text[r] && text[l] == text[len - 1] &&
          text.substr(0, l + 1) == text.substr(r, l + 1)) {
        // cout << text.substr(0, l + 1) << " = " << text.substr(r, l + 1) <<
        // endl;
        int sub_len = len - 2 * (l + 1);
        return rec(text.substr(l + 1, sub_len)) + 2;
      }
      l++, r--;
    }
    return 1;
  }

 public:
  int longestDecomposition(string text) { return rec(text); }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution sol;
  string text = "ghiabcdefhelloadamhelloabcdefghi";
  cout << sol.longestDecomposition(text) << endl;
  text = "merchant";
  cout << sol.longestDecomposition(text) << endl;
  text = "antaprezatepzapreanta";
  cout << sol.longestDecomposition(text) << endl;
  return 0;
}
