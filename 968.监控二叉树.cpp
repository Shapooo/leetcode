/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int minCameraCover(TreeNode* root)
    {
        int result = _helper(root);
        result += root->val == -1 ? 1 : 0;
        return result;
    }
    int _helper(TreeNode* root)
    {
        if (!root)
            return 0;
        int result = _helper(root->left) + _helper(root->right);
        int left {}, right {};
        if (root->left)
            left = root->left->val;
        if (root->right)
            right = root->right->val;
        if (left == -1 || right == -1) {
            root->val = 1;
            return result + 1;
        }

        root->val = !left && !right ? -1 : 0;
        return result;
    }
};
// @lc code=end
