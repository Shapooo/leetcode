#include <algorithm>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    pair<int, int> rec(TreeNode* root)
    {
        int ma { root->val }, mi { root->val };
        if (root->left) {
            auto tmp = rec(root->left);
            mi = min(mi, tmp.first);
            ma = max(ma, tmp.second);
        }
        if (root->right) {
            auto tmp = rec(root->right);
            mi = min(mi, tmp.first);
            ma = max(ma, tmp.second);
        }
        res = max({ res, abs(root->val - mi), abs(root->val - ma) });
        return { mi, ma };
    }

public:
    int maxAncestorDiff(TreeNode* root)
    {
        rec(root);
        return res;
    }
};
// @lc code=end

int main(int argc, char const* argv[])
{
    Solution sol;

    return 0;
}
