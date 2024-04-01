#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
    map<int, map<int, multiset<int>>> nodes {};
    void help(TreeNode* root, int row, int col)
    {
        if (!root) {
            return;
        }
        nodes[col][row].insert(root->val);
        help(root->left, row + 1, col - 1);
        help(root->right, row + 1, col + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        help(root, 0, 0);
        vector<vector<int>> res {};
        for (auto& p : nodes) {
            vector<int> col {};
            for (auto& q : p.second) {
                for (auto& v : q.second) {
                    col.emplace_back(v);
                }
            }
            res.emplace_back(std::move(col));
        }
        return res;
    }
};
// @lc code=end
