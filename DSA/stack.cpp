#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    struct ListNode *next;
};
void push(struct ListNode* &head,int x)
{
    struct ListNode *t=new ListNode;
    if(t==NULL) cout<<"\noverflow!\n";
    else{
        t->val=x;
        t->next=head;
        head=t;
    }
}
int pop(struct ListNode* &head)
{
    int x=-1;
    struct ListNode *p=head;
    if(head==NULL) cout<<"\nunderflouw!\n";
    else{
        head=head->next;
        x=p->val;
        delete p;
    }
    return x;
}
void display(struct ListNode *head)
{
    if(!head) cout<<"\nunderflow\n";
    struct ListNode *p=head;
    while(p)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    ListNode* head = NULL;
    push(head, 10);
    push(head, 20);
    push(head, 30);
    display(head);
    cout << "Popped: " << pop(head) << endl;
    display(head);
}