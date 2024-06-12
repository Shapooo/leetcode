/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    MyLinkedList() { }

    int get(int index)
    {
        ListNode* ptr = head.next;
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
            if (ptr == &head) {
                return -1;
            }
        }
        return (ptr == &head) ? -1 : ptr->val;
    }

    void addAtHead(int val)
    {
        ListNode* node = new ListNode(val, head.next, &head);
        head.next = node;
        node->next->prev = node;
    }

    void addAtTail(int val)
    {
        ListNode* node = new ListNode(val, &head, head.prev);
        head.prev = node;
        node->prev->next = node;
    }

    void addAtIndex(int index, int val)
    {
        ListNode* ptr = &head;
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
            if (ptr == &head) {
                return;
            }
        }
        ListNode* node = new ListNode(val, ptr->next, ptr);
        ptr->next = node;
        node->next->prev = node;
    }

    void deleteAtIndex(int index)
    {
        ListNode* ptr = &head;
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
            if (ptr->next == &head) {
                return;
            }
        }
        ptr->next = ptr->next->next;
        ptr->next->prev = ptr;
    }

private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int val, ListNode* next, ListNode* prev)
            : val(val)
            , next(next)
            , prev(prev)
        {
        }
    };
    ListNode head { 0, &head, &head };
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
