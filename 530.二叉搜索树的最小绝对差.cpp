#include <algorithm>
#include <climits>
using namespace std;
/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int result = INT_MAX;
    int pre = -10e5;
    int getMinimumDifference(TreeNode* root)
    {
        inorder(root);
        return result;
    }
    void inorder(TreeNode* root)
    {
        if (!root)
            return;
        inorder(root->left);
        result = min(result, root->val - pre);
        pre = root->val;
        inorder(root->right);
    }
};
// @lc code=end
