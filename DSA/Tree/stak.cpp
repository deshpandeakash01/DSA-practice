#include<iostream>
#include "stak.h"
using namespace std;
void push(struct Stack* &head,node* x)
{
    struct Stack *t=new Stack;
    if(t==NULL) cout<<"\noverflow!\n";
    else{
        t->val=x;
        t->next=head;
        head=t;
    }
}
node* pop(struct Stack* &head)
{
    node* x=NULL;
    struct Stack *p=head;
    if(head==NULL) cout<<"\nunderflouw!\n";
    else{
        head=head->next;
        x=p->val;
        delete p;
    }
    return x;
}
void display(struct Stack *head)
{
    if(!head) cout<<"\nunderflow\n";
    struct Stack *p=head;
    while(p)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}
node* Top(struct Stack *head)
{
    node* x=(head==NULL)?NULL:head->val;
    return x;
}
bool isEmpty(struct Stack *head)
{
    return head==NULL;
}