/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        l1 = reverse(l1);
        l2 = reverse(l2);
        auto res = add(l1, l2);
        return res;
    }

    ListNode* add(ListNode* l1, ListNode* l2)
    {
        ListNode dummy {};
        int c = 0;
        while (l1 && l2) {
            auto val = l1->val + l2->val + c;
            dummy.next = new ListNode(val % 10, dummy.next);
            l1 = l1->next;
            l2 = l2->next;
            c = val / 10;
        }
        while (l1) {
            auto val = l1->val + c;
            dummy.next = new ListNode(val % 10, dummy.next);
            l1 = l1->next;
            c = val / 10;
        }
        while (l2) {
            auto val = l2->val + c;
            dummy.next = new ListNode(val % 10, dummy.next);
            l2 = l2->next;
            c = val / 10;
        }
        if (c) {
            dummy.next = new ListNode(c, dummy.next);
        }

        return dummy.next;
    }

    ListNode* reverse(ListNode* l)
    {
        ListNode dummy {};
        while (l) {
            auto tmp = l->next;
            l->next = dummy.next;
            dummy.next = l;
            l = tmp;
        }
        return dummy.next;
    }
};
// @lc code=end
