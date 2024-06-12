#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty()) {
            return nullptr;
        }
        auto comp = [](const ListNode* list1, const ListNode* list2) {
            if (!list1)
                return true;
            if (!list2)
                return false;
            return list1->val > list2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> que(
            lists.cbegin(), lists.cend(), comp);
        ListNode dummy;
        ListNode* cur = &dummy;
        while (que.top() != nullptr) {
            cur->next = que.top();
            cur = cur->next;
            que.pop();
            que.push(cur->next);
        }

        return dummy.next;
    }
};
// @lc code=end
