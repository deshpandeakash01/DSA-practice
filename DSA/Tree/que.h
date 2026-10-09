#ifndef QUE_H
#define QUE_H
struct node
{
    struct node *left,*right;
    int val;
};
struct Queue {
    int front;
    int rear;
    int size;
    struct node **Q;
};
void createQueue(struct Queue *q,int size);
bool IsEmpty(struct Queue q);
bool IsFull(struct Queue q);
void enqueue(struct Queue *q, node* x);
struct node *dequeue(struct Queue *q);
void display(struct Queue q);

#endif
