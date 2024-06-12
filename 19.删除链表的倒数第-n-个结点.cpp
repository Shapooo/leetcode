/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode dummy = ListNode(0, head);
        ListNode* right_node = &dummy;
        ListNode* left_node = &dummy;

        for (int i = 0; i <= n; ++i) {
            if (right_node) {
                right_node = right_node->next;
            } else {
                return head;
            }
        }

        while (right_node) {
            right_node = right_node->next;
            left_node = left_node->next;
        }

        left_node->next = left_node->next->next;

        return dummy.next;
    }
};
// @lc code=end
