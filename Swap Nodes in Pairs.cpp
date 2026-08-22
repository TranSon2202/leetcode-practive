#include <iostream>
using namespace std;

struct ListNode
{
    int val; 
    ListNode* next;
};
ListNode* getnode(int x)
{
    ListNode* p = new ListNode;
    p->val = x;
    p->next = NULL;
    return p;
}
void addtail(ListNode*& head, int x)
{
    ListNode* news = getnode(x);
    if(head == NULL)
    {
        head = news;
    }
    else
    {
        ListNode*p = head;
        while( p->next!= NULL) p=p->next;
        p->next=news;
    }

}
void Nhap(ListNode*& head, int n)
{
    int x;
    for(int i=0; i< n; i++)
    {
        cin >> x;
        addtail(head,x);
    }
}
void Xuat(ListNode* head)
{
    ListNode*p = head;
    while(p!=NULL)
    {
        cout << p->val << " ";
        p=p->next;
    }
    cout << endl;
}
ListNode* swapPairs(ListNode* head) {
    ListNode* p = head;
    if(p==NULL) return head;
    ListNode* sau = p->next;
    ListNode* trc = NULL;

    while(sau!=NULL)
    {
        if(p==head)
        {
            p->next = sau->next;
            sau->next = p;
            head=sau;
            trc = p;
        }
        else
        {
            trc->next = p->next;
            p->next = sau->next;
            sau->next = p;
        }
        trc=p;
        p=p->next;
        if(p==NULL) return head;
        sau=p->next;
    }
    return head;

        
}
int main ()
{
    ListNode* head= new ListNode;
    head = NULL;
    int n; cin >> n;
    Nhap(head,n);
    Xuat(head);
    ListNode* result = swapPairs(head);
    Xuat(result);
}