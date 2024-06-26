/*
 * @lc app=leetcode.cn id=2236 lang=cpp
 *
 * [2236] 判断根结点是否等于子结点之和
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
    bool checkTree(TreeNode* root)
    {
        int cv = root->left->val;
        cv += root->right->val;
        return cv == root->val;
    }
};
// @lc code=end
