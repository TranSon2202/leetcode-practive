#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

struct List
{
    ListNode* head;
    ListNode* tail;
};

void Init(List& L)
{
    L.head = NULL;
    L.tail = NULL;
}

ListNode* getnode(int x)
{
    ListNode* p = new ListNode;
    p->val = x;
    p->next = NULL;
    return p;
}

void addtail(List& L, int x)
{
    ListNode* news = getnode(x);

    if(L.head == NULL)
    {
        L.head = news;
        L.tail = news;
    }
    else
    {
        L.tail->next = news;
        L.tail = news;
    }
}

void Nhap(List& L)
{
    int n;
    cin >> n;

    int x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        addtail(L, x);
    }
}

ListNode* mergeTwoLists(ListNode* L1, ListNode* L2)
{
    ListNode* L3;
    ListNode* L1tail = L1;
    ListNode* L2tail = L2;
    if(L1!=NULL) while(L1tail->next != NULL) L1tail = L1tail->next;
    if(L2!=NULL) while(L2tail->next != NULL) L2tail = L2tail->next;

    if(L1 == NULL)
    {
        L3=L2;
    }
    else if(L2 == NULL)
    {
        L3=L1;
    }
    else
    {
        L1tail->next = L2;
        L3=L1;
    }

  
    ListNode* p = L3;

    while(p != NULL)
    {
        ListNode* q = p->next;

        while(q != NULL)
        {
            if(p->val > q->val)
            {
                swap(p->val, q->val);
            }

            q = q->next;
        }

        p = p->next;
    }

  
   return L3;
}

int main()
{
    List L1, L2;

    Init(L1);
    Init(L2);

    Nhap(L1);
    Nhap(L2);

    mergeTwoLists(L1.head, L2.head);

    return 0;
}