#include <iostream>
#include "que.h"
using namespace std;
void createQueue(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=new node*[size];
}
bool IsEmpty(struct Queue q) {
    return q.front == q.rear;
}
bool IsFull(struct Queue q) {
    return (q.rear+1)%q.size==q.front;
}
void enqueue(struct Queue *q, node* x) {
    if (IsFull(*q)) {
        cout << "Queue overflow!!\n";
    } 
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}
struct node* dequeue(struct Queue *q) {
    if (IsEmpty(*q)) {
        cout << "Queue underflow!!\n";
        return NULL;
    } 
    else
    {
        q->front=(q->front+1)%q->size;
        return q->Q[q->front];
    }
}
void display(struct Queue q) {
    if (IsEmpty(q)) {
        cout << "Queue is empty!!\n";
        return;
    }
    int i=(q.front+1)%q.size;
    do
    {
        cout<<q.Q[i]<<" ";
        i=(i+1)%q.size;
    } while(i!=(q.rear+1)%q.size);
    cout << "\n";
}