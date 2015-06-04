//
// Created by Ronald Liu on 3/6/15.
//

#include "leetcode_linked_list.h"
#include <vector>
using namespace std;

struct llheap{
    ListNode** llist;
    int n;
    void pushUp(int idx)
    {
        int p = idx;
        int i = (p-1)/2;
        while(i >= 0)
        {
            if (llist[p]->val < llist[i]->val)
            {
                swap(llist[p], llist[i]);
            }
            else
                break;
            if (i == 0)
                break;
            p=i;
            i = (i-1) / 2;
        }
    }


    void add(ListNode* l)
    {
        llist[n] = l;
        pushUp(n);
        n++;
    }

    void pop()
    {
        int i = 0;
        while(i < n)
        {
            int lci = i*2+1, rci = i*2+2;
            if (lci < n && rci < n)
            {
                if (llist[lci]->val < llist[rci]->val)
                {
                    swap(llist[lci], llist[i]);
                    i = lci;
                }
                else
                {
                    swap(llist[rci], llist[i]);
                    i = rci;
                }
            }
            else if (lci < n)
            {
                swap(llist[lci], llist[i]);
                i = lci;
                break;
            }
            else
                break;
        }

        if (i == n-1)
        {
            n--;
            return;
        }
        swap(llist[n-1], llist[i]);
        pushUp(i);
        n--;
    }

    void modifyTop(ListNode* l)
    {
        pop();
        if (l == nullptr)
            return;
        add(l);
    }

    llheap(vector<ListNode*>& list)
    {
        n = 0;
        llist = new ListNode*[list.size()];
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i]!=nullptr)
            {
                add(list[i]);
            }
        }
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        llheap mheap(lists);
        ListNode* head = nullptr, *tail = nullptr;
        while (mheap.n!=0)
        {
            if (head == nullptr)
                tail = head = mheap.llist[0];
            else
            {
                tail->next = mheap.llist[0];
                tail = tail->next;
            }
            mheap.llist[0] = mheap.llist[0]->next;
            mheap.modifyTop(mheap.llist[0]);
        }
        return head;
    }
};

int main()
{
    Solution s;
    ListNode *h1 = getNNode(std::vector<int> {-8,-7,-7,-5,1,1,3,4});
    ListNode *h2 = getNNode(std::vector<int> {-2});
    ListNode *h3 = getNNode(std::vector<int> {-10,-10,-7,0,1,3});
    ListNode *h4 = getNNode(std::vector<int> {2});
    printNode(h1);
    printNode(h3);
    printNode(h2);
    printNode(h4);
    vector<ListNode*> t = {h1, h2, h3, h4};
    printNode(s.mergeKLists(t));
}