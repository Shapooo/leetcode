#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> result {};
        TreeNode* stk[100];
        int index = 0;
        if (!root) {
            return result;
        }
        stk[index++] = root;
        while (index) {
            auto node = stk[--index];
            while (node) {
                if (node->right) {
                    stk[index++] = node->right;
                }
                result.push_back(node->val);
                node = node->left;
            }
        }

        return result;
    }
};
// @lc code=end
