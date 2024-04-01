#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=2074 lang=cpp
 *
 * [2074] 反转偶数长度组的节点
 */

// @lc code=start

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

// class Solution {
// public:
//     ListNode* reverseEvenLengthGroups(ListNode* head)
//     {
//         auto node = head;
//         int len = 0;
//         while (node) {
//             node = node->next;
//             len++;
//         }
//         node = head;
//         int pass = 1;
//         while (len) {
//             if (pass % 2) {
//                 for (int i = 0; i < pass; ++i) {
//                     node = node->next;
//                 }
//                 len -= pass;
//             } else {
//                 ListNode dummy, *d = &dummy;
//                 for (int i = 0; i < pass; ++i) {
//                 }
//             }
//             len -= pass;
//             pass++;
//             if (pass >= len && len % 2) {
//                 break;
//             }
//         }
//     }
// };
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head)
    {
        vector<int> a {};
        while (head) {
            a.emplace_back(head->val);
            head = head->next;
        }
        int len = a.size();
        int idx = 0, period = 1;
        for (;; period++) {
            int end = idx + period <= len ? idx + period : len;
            if ((end - idx) % 2 == 0) {
                reverse(a.begin() + idx, a.begin() + end);
            }
            if (end >= len) {
                break;
            }
        }
        ListNode dummy {};
        for (int i = 0; i < len; ++i) {
            auto node = new ListNode(a[i], dummy.next);
            dummy.next = node;
        }
        return dummy.next;
    }
};
// @lc code=end
