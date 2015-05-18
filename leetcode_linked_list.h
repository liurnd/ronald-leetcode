//
// Created by Ronald Liu on 18/5/15.
//

#ifndef LEETCODE_LEETCODE_LINKED_LIST_H
#define LEETCODE_LEETCODE_LINKED_LIST_H

#include <stddef.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getNNode(int n)
{
    if (n == 0)
        return nullptr;
    ListNode *head= new ListNode(0);
    ListNode *p=head;
    for (int i = 1; i < n; i++)
    {
        p->next = new ListNode(i);
        p = p->next;
    }
    return head;
}

#include <iostream>
void printNode(ListNode *head)
{
    for (auto p = head; p != nullptr; p = p->next)
        std::cout << p->val << " ";
    std::cout << std::endl;
}

#endif //LEETCODE_LEETCODE_LINKED_LIST_H
