#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root)
    {
        queue<TreeNode*> que {};
        que.push(root);
        while (!que.empty()) {
            auto size = que.size();
            for (int i = 0; i < size - 1; ++i) {
                auto node = que.front();
                que.pop();
                if (node->right)
                    que.push(node->right);
                if (node->left)
                    que.push(node->left);
            }
            auto node = que.front();
            que.pop();
            if (node->right)
                que.push(node->right);
            if (node->left)
                que.push(node->left);
            if (que.empty()) {
                return node->val;
            }
        }
        return 0;
    }
};
// @lc code=end
