/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
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
    int rec(TreeNode* root, int path[])
    {
        if (root == nullptr)
            return 0;
        path[root->val]++;
        if (root->left == nullptr && root->right == nullptr) {
            int odd = 0;
            for (int i = 1; i <= 9; i++) {
                if (path[i] % 2)
                    odd++;
            }
            path[root->val]--;
            return odd <= 1;
        } else {
            int res = rec(root->left, path) + rec(root->right, path);
            path[root->val]--;
            return res;
        }
    }

public:
    int pseudoPalindromicPaths(TreeNode* root)
    {
        int path[10] {};
        return rec(root, path);
    }
};
// @lc code=end
