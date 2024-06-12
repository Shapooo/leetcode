#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return _build(nums, 0, nums.size());
    }
    TreeNode* _build(vector<int>& nums, int start, int end)
    {
        if (end <= start)
            return nullptr;
        int root_index = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[root_index]);
        root->left = _build(nums, start, root_index);
        root->right = _build(nums, root_index + 1, end);
        return root;
    }
};
// @lc code=end
