#include <iostream>
#include "que.h"
#include "stak.h"
using namespace std;
struct node *root=NULL;
void createTree()
{
    struct node *p,*t;
    int x;
    struct Queue q;
    createQueue(&q,100);
    cout<<"enter root : ";
    cin>>x;
    root=new node;
    root->val=x;
    root->left=root->right=0;
    enqueue(&q,root);
    while(!IsEmpty(q))
    {
        p=dequeue(&q);
        if(!p)break;
        cout<<"Enter left of "<<p->val<<" : ";
        cin>>x;
        if(x!=-1)
        {
            t=new node;
            t->val=x;
            t->left=t->right=NULL;
            p->left=t;
            enqueue(&q,t);
        }
        cout<<"Enter right of "<<p->val<<" : ";
        cin>>x;
        if(x!=-1)
        {
            t=new node;
            t->val=x;
            t->left=t->right=NULL;
            p->right=t;
            enqueue(&q,t);
        }
    }

}
void preOrder(struct node *p)
{
    if(p)
    {
        cout<<p->val<<" ";
        preOrder(p->left);
        preOrder(p->right);
    }
}
void inOrder(struct node *p)
{
    if(p)
    {
        inOrder(p->left);
        cout<<p->val<<" ";
        inOrder(p->right);
    }
}
void postOrder(struct node *p)
{
    if(p)
    {
        postOrder(p->left);
        postOrder(p->right);
        cout<<p->val<<" ";
    }
}
void Preorder_iterative(struct node *p)
{
    struct Stack *st;
    while(p||!isEmpty(st))
    {
        if(p)
        {
            cout<<p->val<<" ";
            push(st,p);
            p=p->left;
        }
        else{
            p=pop(st);
            p=p->right;
        }
    }
}
void inorder_iterative(struct node *p)
{
    struct Stack *st;
    while(p||!isEmpty(st))
    {
        if(p)
        {
            push(st,p);
            p=p->left;
        }
        else{
            p=pop(st);
            cout<<p->val<<" ";
            p=p->right;
        }
    }
}
void postorder_iterative(struct node *p)
{
    struct Stack *st1;
    struct Stack *st2;
    push(st1,p);
    while(!isEmpty(st1))
    {
        struct node *t=pop(st1);
        push(st2,t);
        if(t->left) push(st1,t->left);
        if(t->right) push(st1,t->right);
    }
    //printing
    while(!isEmpty(st2))
    {
        struct node *t=pop(st2);
        cout<<t->val<<" ";
    }
}
void levelorderIterative(struct node *p)
{
    struct Queue q;
    cout<<p->data<<" ";
    enqueue(&q,p)
    while(!IsEmpty(q))
    {
        p=dequeue(&q);
        if(p->left)
        {
            cout<<p->left>val<<" ";
            enqueue(&q,p->left);
        }
        if(q->right)
        {
            cout<<p->right->val<<" ";
            enqueue(&q,p->left);
        }
    }
}
int main()
{
    createTree();
    cout<<"preorder : ";
    preOrder(root);
    cout<<"\ninorder : ";
    inOrder(root);
    cout<<"\npostorder : ";
    postOrder(root);
    cout<<"\npreorder Iterative : ";
    Preorder_iterative(root);
    cout<<"\ninorder Iterative : ";
    inorder_iterative(root);
    cout<<"\npostorder Iterative : ";
    postorder_iterative(root);
}
