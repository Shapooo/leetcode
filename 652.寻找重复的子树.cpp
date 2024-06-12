#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        vector<TreeNode*> result {};
        unordered_map<string, int> map {};
        dfs(root, result, map);
        return result;
    }
    string dfs(TreeNode* root, vector<TreeNode*>& result,
        unordered_map<string, int>& map)
    {
        if (!root) {
            return {};
        }
        string fingerPrint = to_string(root->val) + "(" + dfs(root->left, result, map) + ")(" + dfs(root->right, result, map) + ")";
        ++map[fingerPrint];
        if (map[fingerPrint] == 2) {
            result.push_back(root);
        }
        return std::move(fingerPrint);
    }
};
// @lc code=end
