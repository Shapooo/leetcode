/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int dfs(TreeNode* root, int v)
    {
        v = v * 10 + root->val;
        if (!root->left && !root->right) {
            return v;
        }
        int result = 0;
        if (root->left) {
            result = dfs(root->left, v);
        }
        if (root->right) {
            result += dfs(root->right, v);
        }
        return result;
    }

public:
    int sumNumbers(TreeNode* root) { return dfs(root, 0); }
};
// @lc code=end
