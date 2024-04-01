#include <algorithm>
#include <cstdio>
using namespace std;
/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
    int leaf_depth;
    TreeNode* res;
    int depth(TreeNode* root, int d)
    {
        if (!root) {
            return -1;
        }
        int max_depth = max(depth(root->left, d + 1), depth(root->right, d + 1));
        return max_depth == -1 ? d : max_depth;
    }

    bool help(TreeNode* root, int d)
    {
        if (!root) {
            return false;
        }
        if (d == leaf_depth) {
            res = root;
            return true;
        }
        bool l = help(root->left, d + 1), r = help(root->right, d + 1);
        if (l && r) {
            res = root;
        }
        return l || r;
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root)
    {
        leaf_depth = depth(root, 0);
        help(root, 0);
        return res;
    }
};
// @lc code=end
