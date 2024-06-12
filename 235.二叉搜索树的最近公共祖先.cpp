/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode *l, *r;
        if (p->val < q->val) {
            l = p;
            r = q;
        } else {
            l = q;
            r = p;
        }
        while (root) {
            if (root->val < l->val) {
                root = root->right;
            } else if (root->val > r->val) {
                root = root->left;
            } else {
                return root;
            }
        }
        return nullptr;
    }
};
// @lc code=end
