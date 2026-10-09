#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*first=NULL,*last=NULL;
void create(int a[],int n)
{
    struct node *t;
    first=new node;
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    last->next=first;
}
void display(struct node *p)
{
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=first);
    cout<<endl;
}
void recursive_display(struct node *p)
{
    static int flag=0;
    if(p!=first||flag==0)
    {
        flag=1;
        cout<<p->data<<" ";
        recursive_display(p->next);
    }
}
int nodes(struct node *p)
{
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=first);
    return len;
}
void insert(struct node *p,int x,int pos)
{
    struct node *t;
    t=new node;
    t->data=x;
    if(pos<0||pos>nodes(p))
    {
        cout<<"\nINVALID INDEX!!\n";
        return;
    }
    if(pos==0)
    {
        if(p==NULL)
        {
            p=t;
            p->next=p;first=t;
            return;
        }
        else
        {
            p=first;
            while(p->next!=first)p=p->next;
            p->next=t;
            t->next=first;
            first=t;
        }
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
int Delete(struct node *p,int index)
{
    int x;
    if(index<0||index>nodes(p))
    {
        cout<<"INVALID INDEX!!"<<endl;
        return -1;
    }
    if(index==0)
    {
        while(p->next!=first)p=p->next;
        x=first->data;
        if(p==first)
        {
            delete first;
            first=NULL;
        }
        else
        {
            p->next=first->next;
            delete first;
            first=p->next;
        }
    }
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        struct node *q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}
int main()
{
    system("CLS");
    int a[8]={1,2,3,4,5,6,7,8};
    create(a,8);
    display(first);
    recursive_display(first);
    cout<<endl;
    insert(first,0,0);
    Delete(first,0);
    display(first);
    cout<<"number of nodes in linked list : "<<nodes(first)<<endl;
}