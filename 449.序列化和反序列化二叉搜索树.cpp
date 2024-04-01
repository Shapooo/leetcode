#include <cstdio>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (!root) {
            return {};
        }
        string res {};
        res.append(to_string(root->val));
        res.push_back('(');
        res.append(serialize(root->left));
        res.push_back(')');
        res.push_back('(');
        res.append(serialize(root->right));
        res.push_back(')');
        return res;
    }

    TreeNode* help(string& data, int start, int end)
    {
        if (start == end) {
            return NULL;
        }
        int val = 0;
        while (isdigit(data[start])) {
            val *= 10;
            val += data[start] - '0';
            start++;
        }
        auto res = new TreeNode(val);
        start++;
        int ll = start;
        int stk = 1;
        while (stk) {
            if (data[start] == '(') {
                stk++;
            } else if (data[start] == ')') {
                stk--;
            }
            start++;
        }
        int lr = start - 1;
        res->left = help(data, ll, lr);
        stk = 1;
        start++;
        ll = start;
        while (stk) {
            if (data[start] == '(') {
                stk++;
            } else if (data[start] == ')') {
                stk--;
            }
            start++;
        }
        lr = start - 1;
        res->right = help(data, ll, lr);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        return help(data, 0, data.size());
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
