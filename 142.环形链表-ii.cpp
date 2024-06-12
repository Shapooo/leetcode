/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode* a = head;
                ListNode* b = slow;
                while (a != b) {
                    a = a->next;
                    b = b->next;
                }
                return a;
            }
        }

        return nullptr;
    }
};
// @lc code=end
