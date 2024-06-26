#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> result {};
        if (root) {
            _helper(root, result);
        }
        return result;
    }
    void _helper(TreeNode* root, vector<int>& vec)
    {
        if (root->left) {
            _helper(root->left, vec);
        }
        if (root->right) {
            _helper(root->right, vec);
        }
        vec.push_back(root->val);
    }
};
// @lc code=end
