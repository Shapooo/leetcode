/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
    TreeNode* a = nullptr;
    int level = 0;
    bool help(TreeNode* root, int x, int y, int l)
    {
        if (root->val == x) {
            if (a) {
                return l == level &&
            }
        }
    }

public:
    bool isCousins(TreeNode* root, int x, int y)
    {
        return help(root, x, y, 0);
    }
};
// @lc code=end
