#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
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
    int help(TreeNode* root, int ma)
    {
        if (!root) {
            return 0;
        }
        int res = root->val >= ma;
        ma = max(ma, root->val);
        res += help(root->left, ma);
        res += help(root->right, ma);
        return res;
    }

public:
    int goodNodes(TreeNode* root)
    {
        return help(root, -10'001);
    }
};
// @lc code=end
