//
// Created by Ronald Liu on 27/5/15.
//

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        int push = 0;
        ListNode *res = nullptr;
        ListNode *tail = nullptr;
        while(p1!=nullptr||p2!=nullptr)
        {
            int d1=0, d2=0;
            if (p1!=nullptr)
            {
                d1 = p1->val;
                p1 = p1->next;
            }
            if (p2!=nullptr)
            {
                d2 = p2->val;
                p2 = p2->next;
            }
            int result = push + d2 + d1;
            push = result / 10;
            result = result % 10;
            auto tRes = new ListNode(result);
            if (res == nullptr)
            {
                res = tRes;
                tail = tRes;
            }
            else
            {
                tail->next = tRes;
                tail = tRes;
            }
        }

        if (push!=0)
        {
            auto tRes = new ListNode(push);
            tail->next = tRes;
        }

        return res;
    }
};

int main()
{

    return 0;
}
