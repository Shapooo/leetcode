#include <algorithm>
#include <cstdio>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */

// @lc code=start
class Solution {
  void us_merge(vector<int> &unionset, int a, int b) {
    int ah = us_find(unionset, a);
    int bh = us_find(unionset, b);
    unionset[bh] = ah;
  }
  int us_find(vector<int> &unionset, int a) {
    if (unionset[a] == a) {
      return a;
    } else {
      return unionset[a] = us_find(unionset, unionset[a]);
    }
  }

public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int n = accounts.size();
    vector<int> unionset(n);
    unordered_map<string, int> ht{};
    iota(unionset.begin(), unionset.end(), 0);
    for (int i = 0; i < n; ++i) {
      int s = accounts[i].size();
      for (int j = 1; j < s; ++j) {
        auto it = ht.find(accounts[i][j]);
        if (it == ht.end()) {
          ht[accounts[i][j]] = i;
        } else {
          us_merge(unionset, it->second, i);
        }
      }
    }
    vector<vector<string>> res(n);
    for (auto &[s, i] : ht) {
      int id = us_find(unionset, i);
      if (res[id].size() == 0) {
        res[id].push_back(accounts[id][0]);
      }
      res[id].push_back(s);
    }
    res.erase(remove_if(res.begin(), res.end(),
                        [](auto const &v) { return v.size() == 0; }),
              res.end());
    for (auto &v : res) {
      sort(v.begin() + 1, v.end());
    }

    return res;
  }
};
// @lc code=end
