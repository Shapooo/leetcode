/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (!root)
            return nullptr;
        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        if (root->left)
            invertTree(root->left);
        if (root->right)
            invertTree(root->right);
        return root;
    }
};
// @lc code=end
