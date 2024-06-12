/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root)
    {
        _helper(root);
        return root;
    }
    void _helper(TreeNode* root)
    {
        if (!root) {
            return;
        }
        if (root->right) {
            convertBST(root->right);
        }
        root->val += _acc;
        _acc = root->val;
        if (root->left) {
            convertBST(root->left);
        }
    }
    int _acc = 0;
};
// @lc code=end
