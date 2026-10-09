#include<iostream>
#include <climits>
using namespace std;
struct node{
    int data;
    struct node *next;
}*first=NULL,*last=NULL,*second=NULL;
void create(int a[],int n)
{
    int i;
    struct node *t;
    first=new node;
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create2(int a[],int n)
{
    int i;
    struct node *t;
    second=new node;
    second->data=a[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void display_R(struct node *p)
{
    if(p!=NULL)
    {
        display_R(p->next);
        cout<<p->data<<" ";
    }
}
int sum(struct node *p)
{
    int s=0;
    if(p!=NULL)
    {
        s=p->data+sum(p->next);
    }
    return s;
}
int max(struct node *p)
{
    int m=INT_MIN;
    while(p!=NULL)
    {
        if(m<p->data) 
            m=p->data;
        p=p->next;
    }
    return m;
}
struct node *search(struct node *p,int key)
{
    while(p!=NULL)
    {
        if(p->data==key) 
            return p;
        p=p->next;
    }
    return NULL;
}
struct node *imp_search(struct node *p, int key)
{
    struct node *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            if (q != NULL)  //Not already at front
            {
                q->next = p->next;
                p->next = first;
                first = p;
            }
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}
void insert(int pos,int x)
{
    struct node *t,*p;
    if(pos==0)
    {
        t=new node;
        t->data=x;
        t->next=first;
        first=t;
    }
    else if(pos>0)
    {
        p=first;
        for(int i=0;i<pos-1&&p!=NULL;i++)
        {
            p=p->next;
        }
        if(p==NULL) 
        { 
            printf("INVALID POSITION!\n");
            return;
        }
        t=new node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}
int count(struct node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}
void push_back(struct node *p,int x)
{
    struct node *t=new node;
    t->data=x;
    t->next=NULL;
    if(p==NULL)
        first=last=t;
    else{
        last->next=t;
        last=t;
    }
}
void sorted_insert(struct node* p,int x)
{
    struct node *t,*q=NULL;
    t=new node;
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
    }
    else{
        while(p&&p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else{
            t->next=p;
            q->next=t;
        }
    }
}
int pop(struct node *p,int index)
{
    struct node *q=first;
    int item=-1;
    if(index<1||index>count(p))
    {
        cout<<"\nInvalid Index \n";
        return -1;
    }
    if(index==1)
    {
        first=first->next;
        item=q->data;
        delete q;
        return item;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        item=p->data;
        delete p;
    }
    return item;
}
bool check_sorted(struct node *p)
{
    int x=INT_MIN;
    //for(int i=0;i<count(p)-1;i++) //nt efficiant traversing the list twice one in loop and one in count
    while(p!=NULL)
    {
        if(p->data<x) return false;
        x=p->data;
        p=p->next;
    }
    return true;
}
void remove_duplicates(struct node *p)
{
    struct node *q=first->next;
    p=first;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        p->next=q->next;
        delete q;
        q=p->next;
    }
}
void reverse_LL(struct node *p)
{
    struct node *r,*q;
    r=NULL,q=NULL;
    p=first;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void recursive_reverse_LL(struct node *q,struct node *p)
{
    if(p==NULL)
    {
        first=q;
        return;
    }
    recursive_reverse_LL(p,p->next);
    p->next=q;
}
void concatinate(struct node *p,struct node *q)
{
    p=first;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
}
void merge_sorted(struct node *p, struct node *q)
{
    struct node *t = NULL;

    // 1. Pick head of merged list
    if (p->data < q->data) {
        t = p;
        p = p->next;
    } else {
        t = q;
        q = q->next;
    }
    first = last = t;
    last->next = NULL;

    // 2. Merge remaining nodes
    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            last->next = p;
            last=p;
            p=p->next;
        } else {
            last->next = q;
            last=q;
            q=q->next;
        }
        last->next = NULL;
    }

    // 3. Append any leftover nodes
    if (p != NULL)
        last->next = p;
    else
        last->next = q;
}
bool isLoop(struct node *p)
{
    struct node *q;
    p=q=first;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p&&q&&p!=q);
    if(p==q) return true;
    else return false;
}
int main()
{
    system("CLS");
    int A[]={1,3,5,5,8};
    int b[]={1,2,3,4};
    create(A,5);
    create2(b,4);
    display(first);
    cout<<endl;
    /*cout<<"\ndisplay using recursion"<<endl;
    display_R(first);
    int s=sum(first);
    cout<<"\nsum of elements of LL is : "<<s<<endl;
    int m=max(first);
    cout<<"maximum element in LL is : "<<m<<endl;
    struct node *temp=search(first,4);
    if(temp)
        printf("key found at : %p\n",temp);
    else 
        cout<<"key doesn't found!"<<endl;
    struct node *temp2=imp_search(first,4);
    if(temp2)
        printf("key found at : %p\n",temp2);
    else 
        cout<<"key doesn't found!"<<endl;
    insert(3,11);
    display(first);
    push_back(first,5);
    cout<<endl;
    sorted_insert(first,4);
    sorted_insert(first,0);
    sorted_insert(first,15);
    display(first);
    int c=count(first);
    int x=pop(first,4);
    cout<<x<<endl;
    display(first);
    cout<<"\nnumber of nodes in LL is : "<<c<<endl;
    bool a=check_sorted(first);
    cout<<a<<endl;
    remove_duplicates(first);
    display(first);
    reverse_LL(first);
    display(first);
    recursive_reverse_LL(NULL,first);
    display(first);
    concatinate(first,second);
    merge_sorted(first,second);
    //creating loop
    struct node*t1,*t2;
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;
    cout<<isLoop(first);*/ 
}