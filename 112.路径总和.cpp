/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        _targetSum = targetSum;
        return _helper(root, 0);
    }
    bool _helper(TreeNode* root, int init)
    {
        if (!root)
            return false;
        if (!root->left && !root->right) {
            return (root->val + init == _targetSum);
        }
        return _helper(root->left, init + root->val) || _helper(root->right, init + root->val);
    }
    int _targetSum = 0;
};
// @lc code=end
