#include <climits>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> findMode(TreeNode* root)
    {
        _helper(root);
        if (count > max_count) {
            result = { pre };
        } else if (count == max_count) {
            result.push_back(pre);
        }
        return result;
    }
    void _helper(TreeNode* root)
    {
        if (!root)
            return;
        _helper(root->left);

        if (pre == root->val) {
            count++;
        } else {
            if (count > max_count) {
                max_count = count;
                result = { pre };
            } else if (count == max_count) {
                result.push_back(pre);
            }
            count = 1;
            pre = root->val;
        }
        _helper(root->right);
    }
    vector<int> result {};
    int max_count = -1;
    int count = 0;
    int pre = INT_MIN;
};
// @lc code=end
