#include <climits>
#include <stack>
using namespace std;
/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root)
    {
        stack<TreeNode*> stk {};
        long long pre = LONG_LONG_MIN;
        auto node = root;
        while (node) {
            stk.push(node);
            node = node->left;
        }
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            if (node->val <= pre) {
                return false;
            }
            pre = node->val;

            if (node->right) {
                node = node->right;
                while (node) {
                    stk.push(node);
                    node = node->left;
                }
            }
        }
        return true;
    }
};
// @lc code=end
