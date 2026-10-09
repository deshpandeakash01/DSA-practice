#include<iostream>
using namespace std;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL,*last=NULL;
void create(int a[],int n)
{
    struct node *t;
    first=new node;
    first->data=a[0];
    first->next=NULL;
    first->prev=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=a[i];
        t->prev=last;
        last->next=t;
        t->next=NULL;
        last=t;
    }
}
void display(struct node *p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int nodes(struct node *p)
{
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}
void insert(struct node *p,int index,int x)
{
    if(index<0||index>nodes(p))
    {
        cout<<"INVALID INDEX!!\n";
        return;
    }
    if(index==0)
    {
        struct node *t=new node;
        t->prev=NULL;
        t->data=x;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        struct node *t=new node;
        t->data=x;
        t->next=p->next;
        t->prev=p;
        if(p->next)
        {
            p->next->prev=t;
        }
        p->next=t;
    }
}
int Delete(struct node *p,int index)
{
    int x;
    p=first;
    if(index<1||index>nodes(p))
    {
        cout<<"INVALID INDEX!!\n";
        return -1;
    }
    if(index==1)
    {
        first=first->next;
        x=p->data;
        delete p;
    }
    if(first) first->prev=NULL;
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next) p->next->prev=p->prev;
        x=p->data;
        delete p;
    }
 return x;
}
void reverse_LL(struct node *p)
{
    struct node *temp;
    while(p!=NULL)
    {
        /*r=q;
        q=p;
        p=p->next;
        q->prev=p;
        q->next=r; ---------LOGIC IS CORRECT----------*/
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL&&p->next==NULL) 
            first=p;
    } 
//--instead of this try to write a function which doesnt relay on first and returns a new head node--
}
int main()
{
    int a[]={1,2,3,4,5};
    create(a,5);
    display(first);
    reverse_LL(first);
    display(first);
}