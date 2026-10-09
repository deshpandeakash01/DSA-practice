#ifndef STAK_H
#define STAK_H
#include "que.h"
struct Stack
{
    node *val;
    struct Stack *next;
};
void push(struct Stack* &head,node* x);
node* pop(struct Stack* &head);
void display(struct Stack *head);
node* Top(struct Stack *head);
bool isEmpty(struct Stack *head);
#endif