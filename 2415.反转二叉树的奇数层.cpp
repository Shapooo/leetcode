#include <algorithm>
#include <deque>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
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
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        vector<TreeNode*> nodes;
        int level = 0;
        if (!root->left) {
            return root;
        }
        vector<vector<TreeNode*>> levels { { root } };
        while (true) {
            vector<TreeNode*> tmp;
            for (auto& node : levels.back()) {
                if (node->left) {
                    tmp.push_back(node->left);
                }
                if (node->right) {
                    tmp.push_back(node->right);
                }
            }
            if (tmp.empty()) {
                break;
            }
            levels.push_back(tmp);
        }
        for (int i = 1; i < levels.size(); i += 2) {
            reverse(levels[i].begin(), levels[i].end());
        }
        for (int i = 1; i < levels.size(); i++) {
            int j = 0;
            for (auto& node : levels[i - 1]) {
                node->left = levels[i][j++];
                node->right = levels[i][j++];
            }
        }
        return root;
    }
};
// @lc code=end

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* l = new TreeNode(2);
    TreeNode* r = new TreeNode(3);
    root->left = l;
    root->right = r;
    Solution s;
    s.reverseOddLevels(root);
    return 0;
}