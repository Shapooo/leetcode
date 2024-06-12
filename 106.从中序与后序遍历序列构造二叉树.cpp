#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int size = inorder.size();
        return _helper(inorder, postorder, 0, 0, size);
    }

    TreeNode* _helper(vector<int>& inorder, vector<int>& postorder,
        int inorder_index, int postorder_index, int size)
    {
        if (!size) {
            return nullptr;
        }
        if (size == 1) {
            return (new TreeNode(inorder[inorder_index]));
        }
        int root_val = postorder[postorder_index + size - 1];
        auto inorder_root_iter = find(inorder.begin() + inorder_index,
            inorder.begin() + inorder_index + size, root_val);

        int left_size = inorder_root_iter - inorder.begin() - inorder_index;
        int right_size = size - left_size - 1;
        auto left = _helper(inorder, postorder, inorder_index, postorder_index, left_size);

        auto right = _helper(inorder, postorder, inorder_index + left_size + 1,
            postorder_index + left_size, right_size);

        return new TreeNode(root_val, left, right);
    }
};
// @lc code=end
