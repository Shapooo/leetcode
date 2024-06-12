#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        return _helper(nums, 0, nums.size());
    }
    TreeNode* _helper(vector<int>& nums, int left, int right)
    {
        if (right <= left) {
            return nullptr;
        }
        int max_index = left;
        int max = nums[left];
        for (int i = left + 1; i < right; ++i) {
            if (nums[i] > max) {
                max_index = i;
                max = nums[i];
            }
        }
        return new TreeNode(max, _helper(nums, left, max_index),
            _helper(nums, max_index + 1, right));
    }
};
// @lc code=end
