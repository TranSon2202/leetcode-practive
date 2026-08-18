#include <iostream>
using namespace std;
struct node
{
    int val;
    node* next;
};
struct List
{
    node*head;
};
void Init(List& L)
{
    L.head = NULL;
}
node* getnode(int x)
{
    node* p = new node;
    p->val = x;
    p->next= NULL;
    return p;
}
void addhead(List& L, int x)
{
    node* news = getnode(x);
    if(L.head== NULL) L.head=news;
    else
    {
        news->next=L.head;
        L.head= news;
    }
}
void addList(List& L, int n)
{
    int x;
    for(int i=0 ; i<n ; i++)
    {
        cin >> x;
        addhead(L,x);
    }
}
void output(List L)
{
    node*p = L.head;
    while(p!=NULL)
    {
        cout << p->val << " ";
        p=p->next;
    }
}
void Dem(node*head, int& count)
{
    node*p = head;
    while(p!=NULL)
    {
        count++;
        p=p->next;

    }
}
void deleteN(node*& head, int index)
{
    node*p=head;
    while(index > 1)
    {
        p=p->next;
        index--;
    }
    if(index == 0)
    {
        head=p->next;
        p=NULL;
        return;
    }
    else
    {
       node* q = p->next;
       p->next=q->next;
       q=NULL;
       return;
    }
   

}
node* removeNthFromEnd(node* head, int n)
{
    int count = 0 ;
    Dem(head, count);
    if(count == 1) return NULL;
    int index= count -n ;
    deleteN(head,index);
    return head;
}
void outputNode(node* q)
{
    while (q!=NULL)
    {
        cout << q->val << " ";
        q=q->next;
    }
    
}
int main()
{
    List L;
    Init(L);
    int n; cin >> n;
    addList(L,n);
    
    output(L);
    int m;
    cin >> m;
    node* head = L.head;
    node* q = removeNthFromEnd(head, m); 
    outputNode(q);

}