#include<iostream>
using namespace std;
struct Queue {
    int front;
    int rear;
    int size;
    int *Q;
};
bool IsEmpty(struct Queue q) {
    return q.front == q.rear;
}
bool IsFull(struct Queue q) {
    return (q.rear+1)%q.size==q.front;
}
void enqueue(struct Queue *q, int x) {
    if (IsFull(*q)) {
        cout << "Queue overflow!!\n";
    } 
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear] = x;
    }
}
int dequeue(struct Queue *q) {
    if (IsEmpty(*q)) {
        cout << "Queue underflow!!\n";
        return -1;
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
int main() {
    struct Queue q;
    cout << "Enter the size of queue : ";
    cin >> q.size;
    q.Q = new int[q.size];
    q.front = q.rear = 0;   // initialize both to 0
    cout << "\n--- Enqueue operations ---\n";
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(q);
    cout << "\n--- Dequeue operations ---\n";
    cout << "Dequeued: " << dequeue(&q) << "\n";
    cout << "Dequeued: " << dequeue(&q) << "\n";
    display(q);
    cout << "\n--- Wrap-around enqueue ---\n";
    enqueue(&q, 50);
    enqueue(&q, 60);
    display(q);
    cout << "\n--- Overflow case ---\n";
    enqueue(&q, 70);   // should trigger overflow
    display(q);
    cout << "\n--- Dequeue all (Underflow case) ---\n";
    cout << "Dequeued: " << dequeue(&q) << "\n";
    cout << "Dequeued: " << dequeue(&q) << "\n";
    cout << "Dequeued: " << dequeue(&q) << "\n";
    cout << "Dequeued: " << dequeue(&q) << "\n"; // should trigger underflow
    display(q);
}

