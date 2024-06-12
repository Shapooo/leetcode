#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode* root)
    {
        _func(root);
        return root->val;
    }
    int _func(TreeNode* root)
    {
        int son = 0, grand_son = 0;

        if (root->left) {
            grand_son = _func(root->left);
            son = root->left->val;
        }
        if (root->right) {
            grand_son += _func(root->right);
            son += root->right->val;
        }
        root->val = max(root->val + grand_son, son);
        return son;
    }
};
// @lc code=end
