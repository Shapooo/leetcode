#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    inline int _min(int a, int b) { return a > b ? b : a; }
    int minDepth(TreeNode* root)
    {
        queue<TreeNode*> Q {};
        int depth = 0;
        if (!root)
            return 0;
        Q.push(root);
        while (!Q.empty()) {
            depth++;
            auto size = Q.size();
            for (int i = 0; i < size; ++i) {
                auto node = Q.front();
                if (!node->left && !node->right) {
                    return depth;
                }
                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
                Q.pop();
            }
        }
        return depth;
    }
};
// @lc code=end
