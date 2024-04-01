#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
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
    bool isCompleteTree(TreeNode* root)
    {
        queue<TreeNode*> que {};
        que.push(root);
        bool encount_leaf = false;
        while (!que.empty()) {
            auto node = que.front();
            que.pop();
            if (!node->left && node->right) {
                return false;
            }
            if (encount_leaf && (node->left || node->right)) {
                return false;
            }
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            } else {
                encount_leaf = true;
            }
        }
        return true;
    }
};
// @lc code=end
