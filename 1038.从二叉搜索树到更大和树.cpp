/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
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
    int sum = 0;
    int count(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        return count(root->left) + count(root->right) + root->val;
    }
    void help(TreeNode* root)
    {
        if (root == nullptr)
            return;
        help(root->left);
        int tmp = root->val;
        root->val = sum;
        sum -= tmp;
        help(root->right);
    }

public:
    TreeNode* bstToGst(TreeNode* root)
    {
        sum = count(root);
        help(root);
        return root;
    }
};
// @lc code=end
