/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode g = ListNode(0, head);

        ListNode* ptr = head;
        ListNode* back = &g;
        while (ptr) {
            if (ptr->val == val) {
                back->next = ptr->next;
                ptr = ptr->next;
            } else {
                back = ptr;
                ptr = ptr->next;
            }
        }

        return g.next;
    }
};
// @lc code=end
