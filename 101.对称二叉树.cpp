/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root)
    {
        if (!root)
            return true;
        return _helper(root->left, root->right);
    }
    bool _helper(TreeNode* left, TreeNode* right)
    {
        if (!left && !right) {
            return true;
        }

        if (left && right && left->val == right->val) {
            return _helper(left->left, right->right) && _helper(left->right, right->left);
        }

        return false;
    }
};
// @lc code=end
