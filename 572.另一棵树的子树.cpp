#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
    bool check(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot) {
            return true;
        } else if (root && !subRoot || !root && subRoot) {
            return false;
        }
        return root->val == subRoot->val && check(root->left, subRoot->left) &&
               check(root->right, subRoot->right);
    }

  public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot) {
            return true;
        }
        if (root && subRoot) {
            return check(root, subRoot) || isSubtree(root->left, subRoot) ||
                   isSubtree(root->right, subRoot);
        }
        return false;
    }
};
// @lc code=end
