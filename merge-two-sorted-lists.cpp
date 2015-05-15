
#include <iostream>
#include <vector>
#include <cassert>
struct ListNode {
    int val;
    ListNode *next;
    void print()
    {
        std::cout << val;
        if (next)
        {
            next->print();
        }
    }
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getListNode(std::vector<int> valList)
{
    ListNode* head = nullptr;
    ListNode* tail = head;
    for(auto i : valList)
    {
        if (tail==nullptr)
        {
            tail = head = new ListNode(i);
        }
        else{
            tail->next = new ListNode(i);
            tail = tail->next;
        }
    }
    return head;
}

class Solution {
public:
    bool th(bool a, bool b)
    {
        return (a==b);
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *last;
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;

        bool isAce = true;
/*       if (l1->next!=nullptr)
            isAce = (l1->next->val > l1->val);
        else
			if (l2->next!=nullptr)
				isAce = (l2->next->val > l2->val);
				*/
        if (th(isAce, l1->val < l2->val))
        {
            head = last = l1;
            l1 = l1->next;
        }
        else
        {
            head = last = l2;
            l2 = l2->next;
        }

		while (l1 != nullptr || l2 != nullptr)
		{
			bool pickl1 = (l2 == nullptr || (l2 != nullptr && l1 != nullptr && th(isAce, l1->val < l2->val)));
			if (pickl1)
			{
				last->next = l1;
				l1 = l1->next;
			}
			else
			{
				last->next = l2;
				l2 = l2->next;
			}
			last = last->next;
		}

		return head;
    }
};


int main()
{
    ListNode* t = getListNode({1});
	ListNode* t2 = getListNode({2});
	Solution s;
	auto t1= s.mergeTwoLists(t, t2);
    t1->print();
}