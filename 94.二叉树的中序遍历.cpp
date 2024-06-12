#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result {};
        TreeNode* stk[100];
        int index = 0;
        if (!root) {
            return result;
        }

        auto node = root;

        while (true) {
            while (node) {
                stk[index++] = node;
                node = node->left;
            }
            if (!index)
                return result;
            node = stk[--index];
            result.push_back(node->val);
            node = node->right;
        }

        return result;
    }
};
// @lc code=end
