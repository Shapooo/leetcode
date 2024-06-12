/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* ptr = nullptr;
        while (head) {
            auto tmp = head;
            head = tmp->next;
            tmp->next = ptr;
            ptr = tmp;
        }
        return ptr;
    }
};
// @lc code=end
