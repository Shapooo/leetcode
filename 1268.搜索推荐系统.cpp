#include <set>
#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1268 lang=cpp
 *
 * [1268] 搜索推荐系统
 */

// @lc code=start
class Solution {
    struct TrieNode {
        char c;
        TrieNode* children[26] {};
        set<string> products;
        TrieNode(char c = '\0')
            : c(c)
        {
        }
    };
    struct Trie {
        TrieNode root;
        TrieNode* cur;
        Trie()
        {
            cur = &root;
        }
        void insert(string& s)
        {
            for (auto &&c : s)
            {
                if (cur->children[c - 'a'])
            }
            
        }
        vector<string> find(char c)
        {
        }
    };

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
    {
        vector<vector<string>> res {};
        Trie t;
        for (auto&& i : products) {
            t.insert(i);
        }
        for (auto&& c : searchWord) {
            res.push_back(t.find(c));
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    return 0;
}
