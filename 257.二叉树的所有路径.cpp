#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root)
    {
        _helper(root, "");
        return result;
    }
    void _helper(TreeNode* root, string s)
    {
        s.append(to_string(root->val));
        if (!root->left && !root->right) {
            result.push_back(std::move(s));
            return;
        }
        s.append("->");
        if (root->left)
            _helper(root->left, s);
        if (root->right)
            _helper(root->right, std::move(s));
    }
    vector<string> result {};
};
// @lc code=end
