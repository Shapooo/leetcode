#include <bitset>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2115 lang=cpp
 *
 * [2115] 从给定原材料中找到所有可以做出的菜
 */

// @lc code=start
class Solution {
    int cookable[101] {};
    unordered_set<string> sup_set {};
    unordered_map<string, int> recip_map {};
    void help(vector<string>& recipes, vector<vector<string>>& ingredients, int id)
    {
        if (cookable[id] != 0) {
            return;
        }
        cookable[id] = 2;
        for (auto& ing : ingredients[id]) {
            if (sup_set.find(ing) != sup_set.end()) {
                continue;
            }
            auto it = recip_map.find(ing);
            if (it == recip_map.end()) {
                cookable[id] = -1;
                return;
            }
            help(recipes, ingredients, it->second);
            if (cookable[it->second] == -1 || cookable[it->second] == 2) {
                cookable[id] = -1;
                return;
            }
        }
        cookable[id] = 1;
    }

public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies)
    {
        int n = recipes.size();
        for (auto& s : supplies) {
            sup_set.insert(s);
        }
        for (int i = 0; i < n; ++i) {
            recip_map[recipes[i]] = i;
        }
        vector<string> res {};
        for (int i = 0; i < n; ++i) {
            if (!cookable[i]) {
                help(recipes, ingredients, i);
            }
            if (cookable[i] == 1) {
                res.push_back(recipes[i]);
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution sol {};
    vector<string> recipes = { "bread" };
    vector<vector<string>> ingredients = { { "yeast", "flour" } };
    vector<string> supplies { "yeast", "flour", "corn" };
    for (auto& s : sol.findAllRecipes(recipes, ingredients, supplies)) {
        printf("%s ", s.c_str());
    }
    printf("\n");
    recipes = { "bread", "sandwich" };
    ingredients = { { "yeast", "flour" }, { "bread", "meat" } };
    supplies = { "yeast", "flour", "meat" };
    for (auto& s : sol.findAllRecipes(recipes, ingredients, supplies)) {
        printf("%s ", s.c_str());
    }
    printf("\n");
    recipes = { "bread", "sandwich", "burger" };
    ingredients = { { "yeast", "flour" }, { "bread", "meat" }, { "sandwich", "meat", "bread" } };
    supplies = { "yeast", "flour", "meat" };
    for (auto& s : sol.findAllRecipes(recipes, ingredients, supplies)) {
        printf("%s ", s.c_str());
    }
    printf("\n");
    recipes = { "ju", "fzjnm", "x", "e", "zpmcz", "h", "q" };
    ingredients = { { "d" }, { "hveml", "f", "cpivl" }, { "cpivl", "zpmcz", "h", "e", "fzjnm", "ju" }, { "cpivl", "hveml", "zpmcz", "ju", "h" }, { "h", "fzjnm", "e", "q", "x" }, { "d", "hveml", "cpivl", "q", "zpmcz", "ju", "e", "x" }, { "f", "hveml", "cpivl" } };
    supplies = { "f", "hveml", "cpivl", "d" };
    for (auto& s : sol.findAllRecipes(recipes, ingredients, supplies)) {
        printf("%s ", s.c_str());
    }
    printf("\n");
}