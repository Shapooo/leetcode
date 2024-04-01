#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=1372 lang=cpp
 *
 * [1372] 二叉树中的最长交错路径
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
    int res = 0;
    pair<int, int> dfs(TreeNode* root)
    {
        int l {}, r {};
        if (root->left) {
            l = dfs(root->left).second + 1;
            res = max(l, res);
        }
        if (root->right) {
            r = dfs(root->right).first + 1;
            res = max(r, res);
        }
        return { l, r };
    }

public:
    int longestZigZag(TreeNode* root)
    {
        dfs(root);
        return res;
    }
};
// @lc code=end
