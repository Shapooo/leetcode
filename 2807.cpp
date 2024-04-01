
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
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        ListNode* cur = head;
        while (cur && cur->next) {
            int a = cur->val;
            int b = cur->next->val;
            int g = gcd(a, b);
            cur->next = new ListNode(g, cur->next);
            cur = cur->next->next;
        }

        return head;
    }
};
