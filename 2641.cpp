#include <cstdio>
#include <vector>
using namespace std;
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
    vector<int> level_sum {};
    void help(TreeNode* root, int level, int val)
    {
        if (!root) {
            return;
        }
        root->val = val;
        if (level + 1 >= level_sum.size()) {
            return;
        }
        int v = 0;
        if (root->left) {
            v += root->left->val;
        }
        if (root->right) {
            v += root->right->val;
        }
        help(root->left, level + 1, level_sum[level + 1] - v);
        help(root->right, level + 1, level_sum[level + 1] - v);
    }

public:
    TreeNode* replaceValueInTree(TreeNode* root)
    {
        vector<TreeNode*> level { root };
        while (!level.empty()) {
            vector<TreeNode*> tmp {};
            int s {};
            for (auto& node : level) {
                s += node->val;
                if (node->left) {
                    tmp.push_back(node->left);
                }
                if (node->right) {
                    tmp.push_back(node->right);
                }
            }
            level_sum.push_back(s);
            level = std::move(tmp);
        }
        help(root, 0, 0);
        return root;
    }
};