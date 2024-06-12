#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        queue<TreeNode*> Q {};
        vector<vector<int>> result {};
        if (!root) {
            return result;
        }
        Q.push(root);
        while (!Q.empty()) {
            vector<int> level {};
            int size = Q.size();
            for (int i = 0; i < size; ++i) {
                auto node = Q.front();
                Q.pop();
                level.push_back(node->val);
                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
            }
            result.push_back(move(level));
        }

        return result;
    }
};
// @lc code=end
