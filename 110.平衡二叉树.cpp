/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root)
    {
        if (!root)
            return true;
        _height(root);
        return balance;
    }
    int _height(TreeNode* root)
    {
        if (!balance)
            return 0;
        int lH = 0, rH = 0;
        if (root->left)
            lH = _height(root->left);
        if (root->right)
            rH = _height(root->right);
        int diff = lH - rH;
        if (diff > 1 || diff < -1) {
            balance = false;
            return 0;
        }
        return diff > 0 ? lH + 1 : rH + 1;
    }
    bool balance = true;
};
// @lc code=end
