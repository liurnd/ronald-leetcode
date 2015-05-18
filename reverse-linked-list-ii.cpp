//
// Created by Ronald Liu on 18/5/15.
//

#include "leetcode_linked_list.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr)
            return head;
        ListNode *prev = head, *cur = head->next;
        ListNode *lastOrg = nullptr, *lastRev = nullptr;
        for (int i = 1; i < m-1; i++)
        {
            prev = cur;
            cur = cur->next;
        }

        if (m != 1)
            {lastRev = cur;lastOrg = prev;}
        else
            {lastRev = prev;lastOrg = nullptr;}

        if (m!=1)
        {
            prev = cur;cur = cur->next;
        }

        for (int i = 0; i < n-m; i++)
        {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        if (lastOrg)
            lastOrg->next = prev;
        lastRev->next = cur;

        if (lastOrg)
            return head;
        return prev;
    }
};

int main()
{
    ListNode *head = getNNode(1);

    Solution s;
    printNode(s.reverseBetween(head, 1, 1));

    return 0;
}