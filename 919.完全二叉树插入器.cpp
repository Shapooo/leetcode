#include <queue>
using namespace std;
/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
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

class CBTInserter {
    queue<TreeNode*> que {};
    TreeNode* root;

public:
    CBTInserter(TreeNode* root)
        : root(root)
    {
        que.push(root);
        while (true) {
            auto& a = que.front();
            if (a->left && a->right) {
                que.push(a->left);
                que.push(a->right);
                que.pop();
            } else if (a->left) {
                que.push(a->left);
                break;
            } else {
                break;
            }
        }
    }

    int insert(int val)
    {
        auto& a = que.front();
        int ret_val = a->val;
        auto b = new TreeNode(val);
        if (a->left) {
            a->right = b;
            que.pop();
        } else {
            a->left = b;
        }
        que.push(b);
        return ret_val;
    }

    TreeNode* get_root()
    {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end
void rec_del(TreeNode* root)
{
    if (root->left) {
        rec_del(root->left);
    }
    if (root->right) {
        rec_del(root->right);
    }
    delete root;
}
int main()
{
    auto root = new TreeNode(1873);
    auto a = CBTInserter(root);
    vector<int> b = { 90, 67, 90, 21, 2, 41, 49, 73, 9, 85, 29, 68, 28, 18, 31, 44, 41, 41, 86, 39, 68, 34, 33, 45, 77, 4, 16, 27, 66, 59, 1, 49, 20, 29, 11, 77, 90, 86, 21, 14, 36, 12, 85, 39, 79, 42, 77, 82, 67, 65, 46, 26, 50, 80, 55, 84, 71, 78, 36, 80, 52, 42, 11, 56, 66, 40, 13, 4, 10, 71, 65, 15, 49, 31, 24, 86, 28, 43, 15, 5, 54, 75, 58, 84, 89, 43, 75, 70, 3, 21, 77, 26, 37, 71, 4, 41, 38, 33, 70, 19, 19, 12, 86, 20, 61, 36, 58, 68, 77, 17, 85, 17, 90, 69, 53, 11, 30, 86, 35, 69, 60, 25, 18, 67, 23, 69, 0, 4, 82, 82, 50, 30, 4, 9, 8, 38, 6, 34, 75, 29, 61, 47, 59, 84, 87, 46, 37, 84, 3, 56, 40, 83, 21, 84, 84, 5, 37 };
    vector<int> c = { 3275, 4521, 4918, 182, 4132, 43, 2497, 1000, 3743, 3006, 4227, 2698, 599, 107, 3719, 174, 2971, 2165, 2028, 772, 4262, 565, 2712, 3882, 4937, 326, 4352, 2166, 1149, 3654, 4977, 3973, 4090, 2099, 3015, 107, 278, 973, 3112, 4698, 3747, 519, 3037, 2725, 2396, 2171, 4404, 1874, 1007, 3535, 972, 2975, 2600, 2162, 1243, 4056, 3540, 3167, 752, 4838, 2914, 4003, 888, 2337, 3722, 490, 2265, 4519, 228, 4442, 4360, 3651, 4764, 3037, 976, 4468, 931, 4076, 4502, 4316, 2465, 2031, 2788, 3181, 1371, 4582, 4196, 3369, 2841, 4084, 2167, 2417, 2418, 4126, 3589, 998, 575, 4648, 4754, 800, 4204, 4080, 399, 2325, 863, 890, 2115, 2965, 1685, 1807, 3664, 3471, 879, 81, 1433, 4045, 2317, 2912, 3355, 4180, 824, 1140, 1958, 1341, 2680, 1814, 1191, 768, 4178, 1064, 4683, 1220, 2650, 2183, 507, 2074, 4793, 1637, 1770, 3917, 3278, 4190, 2825, 4639, 2562, 792, 1661, 4170, 3132, 2149, 1912, 1793, 2567, 3201, 450, 4599, 863, 81, 597, 2564, 4309, 4940, 3434, 2217, 1437, 2643, 3872, 2598, 4331, 557, 3221, 1834, 4441, 2278, 3256, 2182, 395, 15, 831, 1426, 4883, 4703, 2795, 325, 311, 2774, 248, 4301, 3139, 4799, 2400, 2228, 2859, 3338, 752, 2701, 2046, 4608, 2012, 146, 2471, 4619, 2310, 37, 2366, 2711, 990, 923, 975, 3453, 2326, 1018, 4746, 500, 4526, 1578, 986, 4836, 3496, 1733, 2172, 2151, 1092, 2774, 783, 236, 1261, 253, 3491, 3280, 1245, 3855, 2281, 3544, 2569, 70, 3818, 2508, 2900, 3997, 4000, 4365, 1705, 4771, 209, 20, 3030, 4183, 987, 47, 1889, 708, 2464, 2734, 4961, 1628, 1084, 1592, 1167, 272, 4078, 838, 3803, 2998, 809, 3594, 2170, 1442, 2526, 1187, 749, 2533, 4975, 1385, 1706, 1668, 4149, 2413, 382, 2217, 4056, 3550, 962, 928, 3753, 606, 3545, 98, 4990, 2944, 3021, 898, 725, 4525, 1139, 3912, 2371, 427, 1146, 3596, 2677, 1315, 2948, 1432, 1882, 4780, 1035, 1423, 1347, 4269, 1929, 3235, 104, 4973, 2360, 2265, 923, 3078, 2943, 3500, 1137, 2880, 2789, 2633, 471, 916, 596, 809, 1056, 1669, 975, 1339, 3480, 3654, 1952, 4706, 4486, 1152, 502, 3945, 34, 1895, 1080, 149, 3574, 3465, 3218, 1912, 978, 4333, 15, 3336, 4062, 1750, 418, 1862, 869, 664, 3251, 3779, 2875, 4871, 452, 3689, 542, 635, 2027, 2648, 4212, 2457, 4277, 3903, 4144, 3502, 3320, 4251, 2567, 320, 347, 86, 2743, 3334, 2296, 691, 4111, 769, 1998, 3877, 1914, 349, 2687, 4827, 4737, 4556, 412, 3605, 4013, 4843, 3817 };
    for (auto n : c) {
        a.insert(n);
    }
    a.get_root();
    rec_del(root);
}
