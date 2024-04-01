#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=979 lang=cpp
 *
 * [979] 在二叉树中分配硬币
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

public:
    int distributeCoins(TreeNode* root)
    {
        helper(root);
        return res;
    }
    int helper(TreeNode* root)
    {
        if (!root) {
            return 0;
        }
        auto left = helper(root->left);
        auto right = helper(root->right);
        int step = abs(left) + abs(right);
        res += step;
        int coin = left + right + root->val - 1;
        return coin;
    }
};
// @lc code=end
