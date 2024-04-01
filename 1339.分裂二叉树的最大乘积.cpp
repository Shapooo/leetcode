#include <algorithm>
#include <cstdio>
using namespace std;
/*
 * @lc app=leetcode.cn id=1339 lang=cpp
 *
 * [1339] 分裂二叉树的最大乘积
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

long long MOD = 1000'000'007;
class Solution {
    long long ma = 0;
    int total;
    int subtree_sum(TreeNode* root)
    {
        if (!root) {
            return 0;
        }
        int l = subtree_sum(root->left);
        int r = subtree_sum(root->right);
        root->val += l + r;
        return root->val;
    }
    void help(TreeNode* root)
    {
        if (!root) {
            return;
        }
        ma = max(ma, ((long long)total - root->val) * root->val);
        printf("%lld %d %d\n", ma, total - root->val, root->val);
        help(root->left);
        help(root->right);
    }

public:
    int maxProduct(TreeNode* root)
    {
        total = subtree_sum(root);
        help(root);
        return ma % MOD;
    }
};
// @lc code=end
