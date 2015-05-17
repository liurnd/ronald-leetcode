#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#include <iostream>
using namespace std;
void printLinkList(ListNode* head)
{
    while(head!= nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode *prev = head, *cur = head->next;
        head->next = nullptr;

        while(cur!=nullptr)
        {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *p1, *p2;
        p1= head;p2=head;
        if (p1==nullptr)
            return;
        while(true)
        {
            p2 = p2->next;
            if (p2==nullptr)
                break;
            p2 = p2->next;
            if (p2==nullptr)
                break;
            p1 = p1->next;
        }
        p2 = p1->next;
        p1->next = nullptr;
        p1 = p2;

        if (p1==nullptr)
            return;

        p2 = reverseList(p1);
        p1 = head;

        while (true)
        {
            ListNode *n1=p1->next, *n2=p2->next;
            p1->next = p2;
            p2->next = n1;
            p1 = n1;
            p2 = n2;
            if (p2 == nullptr)
                break;
        }
    }
};


int main()
{
    Solution s;
    ListNode a(1), b(2), c(3), d(4), e(5);
    //a.next = &b;
    //b.next = &c;
    //c.next = &d;
    //d.next = &e;
    s.reorderList(&a);
    printLinkList(&a);
    return 0;
}